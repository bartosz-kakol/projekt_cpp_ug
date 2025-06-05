#pragma once

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTimer>

#include "Serializer/Impl/Serializer/JSONSerializer.h"
#include "Utils/Base/Interfaces/ISpawner.h"
#include "World/Base/Interfaces/IWorld.h"


QT_BEGIN_NAMESPACE
namespace Ui { class WorldViewerWindow; }
QT_END_NAMESPACE

class WorldViewerWindow final : public QMainWindow {
    Q_OBJECT

    IWorld& world;
    ISpawner& spawner;
    QStandardItemModel* worldViewModel;
    std::unordered_map<std::string, QColor> organismColors{};
    QTimer* automaticTurnTimer;
    std::unique_ptr<JSONSerializer> serializer;

    void init() const;

    void drawMap() const;

    void updateWorldView() const;
public:
    explicit WorldViewerWindow(IWorld& world, ISpawner& spawner, QWidget *parent = nullptr);

    ~WorldViewerWindow() override;

    void logMessage(const std::string& message) const;
    bool isLoggingEnabled() const;

    void mapOrganismColor(const std::string& species, const QColor& color);
private slots:
    void onSpawnBtnClicked() const;
    void onNextTurnBtnClicked() const;
    void onAutomaticTurnTimerTick() const;
    void onSaveStateBtnClicked();
    void onLoadStateBtnClicked();

private:
    Ui::WorldViewerWindow *ui;
};