#include "WorldViewerWindow.h"

#include <iostream>

#include "ui_WorldViewerWindow.h"
#include <QFileDialog>

WorldViewerWindow::WorldViewerWindow(IWorld& world, ISpawner& spawner, QWidget *parent)
    :
        QMainWindow(parent),
        world(world),
        spawner(spawner),
        worldViewModel(new QStandardItemModel()),
        automaticTurnTimer(new QTimer(this)),
        serializer(std::make_unique<JSONSerializer>()),
        ui(new Ui::WorldViewerWindow)
{
    ui->setupUi(this);

    ui->spawnXChooser->setRange(0, world.getWidth() - 1);
    ui->spawnYChooser->setRange(0, world.getHeight() - 1);

    connect(ui->spawnBtn, &QPushButton::clicked, this, &WorldViewerWindow::onSpawnBtnClicked);
    connect(ui->nextTurnBtn, &QPushButton::clicked, this, &WorldViewerWindow::onNextTurnBtnClicked);
    connect(automaticTurnTimer, &QTimer::timeout, this, &WorldViewerWindow::onAutomaticTurnTimerTick);
    connect(ui->automaticTurnsCheckBox, &QCheckBox::toggled, this, [=](const bool checked){
        if (checked) {
            automaticTurnTimer->start(100);
        } else {
            automaticTurnTimer->stop();
        }
    });
    connect(ui->saveStateBtn, &QPushButton::clicked, this, &WorldViewerWindow::onSaveStateBtnClicked);
    connect(ui->loadStateBtn, &QPushButton::clicked, this, &WorldViewerWindow::onLoadStateBtnClicked);

    show();

    init();
}

WorldViewerWindow::~WorldViewerWindow() {
    delete ui;
}

void WorldViewerWindow::init() const
{
    drawMap();

    updateWorldView();

    for (const auto& name : spawner.getAvailableOrganismNames())
    {
        ui->spawnChooser->addItem(QString::fromStdString(name));
    }
}

void WorldViewerWindow::drawMap() const
{
    const auto w = world.getWidth();
    const auto h = world.getHeight();

    worldViewModel->setColumnCount(w);
    worldViewModel->setRowCount(h);

    const auto widgetWidth = ui->worldGrid->width();
    const auto widgetHeight = ui->worldGrid->height();

    const auto columnWidth = widgetWidth / w;
    const auto rowHeight = widgetHeight / h;

    ui->worldGrid->setModel(worldViewModel);
    ui->worldGrid->setStyleSheet("background: white; color: black;");

    for (int x = 0; x < w; x++)
    {
        ui->worldGrid->setRowHeight(x, rowHeight);

        for (int y = 0; y < h; y++)
        {
            ui->worldGrid->setColumnWidth(y, columnWidth);
        }
    }
}

void WorldViewerWindow::logMessage(const std::string& message) const
{
    ui->logBox->addItem(QString::fromStdString(message));
    ui->logBox->scrollToBottom();
}

bool WorldViewerWindow::isLoggingEnabled() const
{
    return ui->enableLogsCheckBox->isChecked();
}

void WorldViewerWindow::mapOrganismColor(const std::string& species, const QColor& color)
{
    organismColors[species] = color;
}

void WorldViewerWindow::updateWorldView() const
{
    const auto w = world.getWidth();
    const auto h = world.getHeight();

    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            if (const auto& organisms = world.getOrganismsFromPosition(x, y); !organisms.empty())
            {
                const auto& org = *std::max_element(
                    organisms.begin(), organisms.end(),
                    [](const IOrganism* a, const IOrganism* b)
                    {
                        return a->getInitiative() < b->getInitiative();
                    }
                );

                worldViewModel->setItem(
                    y, x,
                    new QStandardItem(
                        QString::number(org->getPower()) + "/" + QString::number(org->getLiveLength()) + "\n" +
                        QString::number(organisms.size())
                    )
                );

                const auto item = worldViewModel->item(y, x);
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(QFont("Arial", 12, QFont::Bold));

                // Kolor tekstu w komórce
                const auto& species = org->getSpecies();
                item->setForeground(
                    organismColors.find(species) != organismColors.end() ?
                         organismColors.at(org->getSpecies())
                         :
                         Qt::black
                );
            }
            else
            {
                worldViewModel->setItem(y, x, new QStandardItem(""));
            }
        }
    }

    ui->turnLabel->setText("Tura: " + QString::number(world.getTurn()));
}

void WorldViewerWindow::onSpawnBtnClicked() const
{
    const auto& opt = ui->spawnChooser->currentText();
    const auto& spawnPosition = Position(
        ui->spawnXChooser->value(),
        ui->spawnYChooser->value()
    );

    spawner.spawn(
        opt.toStdString(),
        SpawnSettings{
            .position = spawnPosition
        }
    );

    updateWorldView();
}

void WorldViewerWindow::onNextTurnBtnClicked() const
{
    world.makeTurn();
    updateWorldView();
}

void WorldViewerWindow::onAutomaticTurnTimerTick() const
{
    if (ui->automaticTurnsCheckBox->isChecked()) {
        ui->nextTurnBtn->click();
    }
}

void WorldViewerWindow::onSaveStateBtnClicked()
{
    const QString fileName = QFileDialog::getSaveFileName(
        this,
        "Zapisz stan świata",
        "",
        "Pliki JSON (*.json);;Wszystkie Pliki (*)"
    );

    if (fileName.isEmpty()) return;

    auto outputFile = std::ofstream(fileName.toStdString());

    if (!outputFile.is_open()) {
        logMessage("Nie można otworzyć pliku:");
        logMessage(fileName.toStdString());
        return;
    }

    serializer->dump(outputFile, &world);

    logMessage("Zapisano stan świata do pliku:");
    logMessage(fileName.toStdString());
}

void WorldViewerWindow::onLoadStateBtnClicked()
{
    const QString fileName = QFileDialog::getOpenFileName(
        this,
        "Otwórz zapisany stan świata",
        "",
        "Pliki JSON (*.json);;Wszystkie Pliki (*)"
    );

    if (fileName.isEmpty()) return;

    auto inputFile = std::ifstream(fileName.toStdString());

    if (!inputFile.is_open()) {
        logMessage("Nie można otworzyć pliku:");
        logMessage(fileName.toStdString());
        return;
    }

    serializer->load(inputFile, &world);

    drawMap();
    updateWorldView();

    logMessage("Załadowano stan świata z pliku:");
    logMessage(fileName.toStdString());
}
