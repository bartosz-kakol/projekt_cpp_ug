#include "WorldViewerWindow.h"

#include <iostream>

#include "ui_WorldViewerWindow.h"

WorldViewerWindow::WorldViewerWindow(IWorld& world, ISpawner& spawner, QWidget *parent)
    :
        QMainWindow(parent),
        world(world),
        spawner(spawner),
        worldViewModel(new QStandardItemModel()),
        ui(new Ui::WorldViewerWindow)
{
    ui->setupUi(this);

    ui->spawnXChooser->setRange(0, world.getWidth() - 1);
    ui->spawnYChooser->setRange(0, world.getHeight() - 1);

    connect(ui->spawnBtn, &QPushButton::clicked, this, &WorldViewerWindow::onSpawnBtnClicked);
    connect(ui->nextTurnBtn, &QPushButton::clicked, this, &WorldViewerWindow::onNextTurnBtnClicked);

    show();

    init();
}

WorldViewerWindow::~WorldViewerWindow() {
    delete ui;
}

void WorldViewerWindow::init() const
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

    updateWorldView();

    for (const auto& name : spawner.getAvailableOrganismNames())
    {
        ui->spawnChooser->addItem(QString::fromStdString(name));
    }
}

void WorldViewerWindow::logMessage(const std::string& message) const
{
    ui->logBox->addItem(QString::fromStdString(message));
    ui->logBox->scrollToBottom();
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
                        QString::fromStdString(org->toString() + "\n") +
                        QString::number(organisms.size())
                    )
                );

                const auto item = worldViewModel->item(y, x);
                item->setTextAlignment(Qt::AlignCenter);
                item->setForeground(QColor(Qt::darkGray));
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
