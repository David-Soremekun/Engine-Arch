#include "EnemyEntity.h"

EnemyEntity::EnemyEntity(std::string name)
{
	gfxName = name;
	e_entityHealth = 60;

	e_entityPosition = Vector2(0, 0);
	startPos = e_entityPosition;
}

Vector2 EnemyEntity::lerp(float v1, float v2, float t)
{
	//(1.0f - t) * v1 + t * v2)
	Vector2 tempVec;
	tempVec.x = (1.0f - t) * v1 + t * v2;
	tempVec.x = e_entityPosition.x;
	return Vector2(e_entityPosition);
}

void EnemyEntity::EnemyMovement()
{
	lerp(startPos.x, endPos.x, movementTick);

}

void EnemyEntity::Update(World& world)
{
	EnemyMovement();
}
