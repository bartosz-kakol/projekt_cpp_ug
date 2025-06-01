#include <QApplication>

#include "Spawner.h"
#include "UILogger.h"
#include "UI/WorldViewerWindow.h"
#include "World/Creator.h"
#include "World/World.h"
#include "World/Base/ActionBase.h"
#include "World/Impl/Animal/Sheep.h"
#include "World/Impl/Plant/Grass.h"
#include "World/Impl/Behavior/SheepBehavior.h"
#include "World/Impl/Behavior/DefaultBehavior.h"
#include "World/Impl/Identifier/SequentialIdentifier.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	auto world = World(18, 18);

	auto identifier = SequentialIdentifier();
	auto creator = Creator(world, identifier);

	auto spawner = Spawner(creator);
	spawner.map<Grass, DefaultBehavior>("Trawa");
	spawner.map<Sheep, SheepBehavior>("Owca");

	const WorldViewerWindow win(world, spawner);

	ActionBase::logger = std::make_unique<UILogger>(win);

	return app.exec(); // NOLINT(*-static-accessed-through-instance)
}
