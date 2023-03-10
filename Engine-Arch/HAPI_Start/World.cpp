#include "World.h"
#include "Entity.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "SoundManager.h"
#include "BulletEntity.h"
const int kNumOfBulletsInPool = 50;

World::~World()
{
	// Deletes are the objects
	//delete audio;
	delete enemy;
	delete player;
	delete visuals;
	delete sound;
	for(auto entity: m_entities) 
	{
		
		delete entity;
		
	}
	
}

void World::LoadLevel()
{	
	
	// Loads in a sprites and sound into level
	if(!visuals->CreateSprite("backgroundImage", false,"horizon-stars.tga"))
		return;
	if(!visuals->CreateSprite("playerCharacter", true,"player-sprite.tga"))
		return;
	if (!visuals->CreateSprite("bullet", true, "fire-bullet.tga"))
		return;
	if (!visuals->CreateSprite("coin", true, "coin.tga"))
		return;
	if (!visuals->CreateSprite("enemyCharacter",true,"enemy-ship.tga")) 
		return;
	
	

	if (!sound->LoadSound("piano-melody","stage-music"))
		return;
	if (!sound->LoadSound("arcade-shoot", "shoot-sound"))
		return;

	
	
}

void World::Run()
{
	// Initialises all the valeues for the player, enemy, Bullet classes
	sound = new SoundManager();
	visuals = new Visualisation(HAPI.GetScreenPointer());
	LoadLevel();
		
	sound->PlaySound("piano-melody.wav", false, true, 1.0f, 0.0f, 1.0f);

	// Setup the Player
	player = new PlayerEntity("playerCharacter");
	//player->SetAlive();
	m_entities.push_back(player);
	//player->getEntityPosition();

	// Setup the Enemy
	enemy = new EnemyEntity("enemyCharacter");
	enemy->IsAlive();
	m_entities.push_back(enemy);

	m_bulletStartIndex = m_entities.size()+1;

	for (size_t i = 0; i < 50; i++) {
		BulletEntity *newBullet = new BulletEntity("bullet");
		m_entities.push_back(newBullet);
	}

	while (HAPI.Update())
	{

		for (Entity* entity: m_entities)
		{
			entity->Update(*this);
			
		}

		// Collisions go here
		/*for (Entity* entity : m_entities)
		{
			if (entity->GetSide() != Side::eNeutral)
			{
				if (entity->GetSide() != Side::eEnemy) {
					CheckCollisions(*entity);

				}
				

			}
			
		}*/
		
		// ClearScreen
		visuals->ClearScreen(Width, Height);
		
		
		m_entities[0]->Render(visuals);
			
		
		// Check it right inputhas been entered to screenshot
		CheckToScreenshot();
		hasWon();
		DetectWin();
		
		
		//HAPI.LimitFrameRate(120);
		HAPI.SetShowFPS(true);
	}

}

void World::CheckToScreenshot()
{
	_ASSERT(player);
	if (player->ScreenTrigger()) {
		visuals->ScreenShot(Width,Height);
		std::cerr << "Screenshot Taken!";
	}
	
}
void World::DetectWin()
{
	if (m_wonGame) {
		HAPI.RenderText(20, 700, HAPI_TColour(255, 255, 255), "HOORAY YOU HAVE WON", 48);

	}
}
bool World::hasWon()
{
	if (player->getEntityPosition() == GoldenSection) {
		m_wonGame = true;
		return true;
	}
	else{
		m_wonGame = false;
		return false;

	}
}
bool World::CheckCollisions(Entity& otherEntity)
{
	// Do Collisions
	if (player->getRect().CompletelyContains(otherEntity.getRect())==false) 
	{
		player->GetEntityHealth()-20;
	}
	else {

	}
	return false;
}

void World::FireBullets(Side eSide, Vector2 velocity, Vector2 startPos)
{
	for (size_t i=m_bulletStartIndex; i < m_bulletStartIndex + kNumOfBulletsInPool; i++)
	{
		if (m_entities[i]->IsAlive() == false) {
			m_entities[i]->SetAlive();
			sound->PlaySound("arcade-shoot.wav", 1.0f, true,0.0f,0.0f,0.0f);
			//startPos+Vector2(0.0f,startPos.DotProduct(Vector2(0.0f,m_entities[i]->GetSpeed())));
			
			
		}
	}
}




