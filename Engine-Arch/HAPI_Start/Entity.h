#pragma once
#include <string>
#include <HAPI_lib.h>
#include "Vector2.h"
#include "Rectangle.h"
using namespace HAPISPACE;
class World;
class Visualisation;

enum class Type {
	ePlayer,
	eEnemy,
	ePickup,
	eExplosion

};

enum class Side {
	eNeutral,
	ePlayer,
	eEnemy
};

class Entity
{
private:
	std::string e_gfxName;
	
	int Width{ 1024 };
	int Height{ 768 };
	

protected:
	
	bool e_isAlive{ false };
	int e_entityHealth;
	Vector2 e_entityPosition;
	Rectangle e_entityBox();
	
	
public:
	//bool CheckForCollision(Entity &otherEntity);
	Entity();
	~Entity();
	

	virtual void Update(World& world);
	virtual void Render(Visualisation* visuals);
	virtual Vector2 GetPlayerPos() = 0;
	
	virtual Side GetSide() = 0;
	virtual Type GetType() = 0;
	virtual bool ScreenTrigger() = 0;
	virtual float GetSpeed() = 0;

	//Rectangle setBox(Visualisation* visuals, const std::string& spriteName);
	
	void SetAlive() {
		e_isAlive = true;
	}
	int GetEntityHealth() { return e_entityHealth; }
	bool IsAlive() { return e_isAlive; }
	
	Rectangle getRect() { return e_entityBox(); }
	virtual Vector2 getEntityPosition() = 0;

	
};



