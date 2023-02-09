#include "Entity.h"
#include "Rectangle.h"
#include "Visualisation.h"
Rectangle Entity::e_entityBox()
{
	return Rectangle(0,Width,0,Height);
}
Entity::~Entity()
{
	
}


void Entity::Update(World& world)
{
	
}

void Entity::Render(Visualisation* visuals) {
	
	visuals->DrawSprite("backgroundImage", e_entityBox(), Vector2(0, 0), 0);
	visuals->DrawSprite("coin", e_entityBox(), Vector2(50, 50), 0);
	visuals->DrawSprite("playerCharacter", e_entityBox(), e_entityPosition, 0);
	visuals->DrawSprite("enemyCharacter", e_entityBox(),Vector2(200.f,600.f), 0);
	//visuals->DrawSprite("bullet",e_entityBox(),e_entityPosition,0);
	
	
	
	
}


