#include <QApplication>

#include "World/World.h"
#include "World/Creator.h"

#include "World/Base/ActionBase.h"

#include "World/Impl/Identifier/SequentialIdentifier.h"
#include "World/Impl/Animal/Sheep.h"
#include "World/Impl/Animal/Wolf.h"
#include "World/Impl/Plant/Grass.h"
#include "World/Impl/Plant/Dandelion.h"

#include "World/Impl/Behavior/Animal/SheepBehavior.h"
#include "World/Impl/Behavior/Plant/GrassBehavior.h"
#include "World/Impl/Behavior/Plant/DandelionBehavior.h"
#include "World/Impl/Behavior/Animal/WolfBehavior.h"

#include "UI/Utils/Spawner.h"

#include "UI/WorldViewerWindow.h"
#include "UI/Utils/UILogger.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	auto world = World(std::make_unique<SequentialIdentifier>(), 21, 21);

	// Do poprawnej serializacji/deserializacji
	world.registerSerializationOrganismCreator<Sheep>("Sheep");
	world.registerSerializationOrganismCreator<Wolf>("Wolf");
	world.registerSerializationOrganismCreator<Grass>("Grass");
	world.registerSerializationOrganismCreator<Dandelion>("Dandelion");

	world.registerSerializationBehaviorCreator<SheepBehavior>("SheepBehavior");
	world.registerSerializationBehaviorCreator<WolfBehavior>("WolfBehavior");
	world.registerSerializationBehaviorCreator<GrassBehavior>("GrassBehavior");
	world.registerSerializationBehaviorCreator<DandelionBehavior>("DandelionBehavior");

	auto creator = Creator(world);

	auto spawner = Spawner(creator);
	spawner.map<Sheep, SheepBehavior>("Owca");
	spawner.map<Wolf, WolfBehavior>("Wilk");
	spawner.map<Grass, GrassBehavior>("Trawa");
	spawner.map<Dandelion, DandelionBehavior>("Mniszek lekarski");

	WorldViewerWindow win(world, spawner);

	ActionBase::logger = std::make_unique<UILogger>(win);

	win.mapOrganismColor("Sheep", Qt::lightGray);
	win.mapOrganismColor("Wolf", Qt::darkGray);
	win.mapOrganismColor("Grass", Qt::darkGreen);
	win.mapOrganismColor("Dandelion", Qt::green);

	return app.exec(); // NOLINT(*-static-accessed-through-instance)
}
