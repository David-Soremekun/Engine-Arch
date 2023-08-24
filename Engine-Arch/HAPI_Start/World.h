#pragma once

#include <vector>
#include "Entity.h"
#include "BulletEntity.h"
#include "PlayerEntity.h"

#include "Visualisation.h"

#include "Rectangle.h" 

class SoundManager;
class EnemyEntity;
class World
{
private:
	int Width = 1024;
	int Height = 768;
	bool m_wonGame = false;

	
	Vector2 GoldenSection=Vector2(50.0f,50.0f);
	//Audio* audio;
	EnemyEntity* enemy;
	PlayerEntity* player;

	Visualisation* visuals;
	SoundManager* sound;
	
	size_t m_bulletStartIndex{0};
	
	std::vector<Entity*>m_entities;
public:
	World();
	~World();
	void Run();
	void LoadLevel();
	void FireBullets(Side eSide, Vector2 velocity, Vector2 startPos);
	void CheckToScreenshot();
	
	bool CheckCollisions(Entity& otherEntity);
	
};

