#pragma once

#include <QMainWindow>
#include <QStandardItemModel>

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

    void init() const;

    void updateWorldView() const;
public:
    explicit WorldViewerWindow(IWorld& world, ISpawner& spawner, QWidget *parent = nullptr);

    ~WorldViewerWindow() override;

    void logMessage(const std::string& message) const;
private slots:
    void onSpawnBtnClicked() const;
    void onNextTurnBtnClicked() const;

private:
    Ui::WorldViewerWindow *ui;
};