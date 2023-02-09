#pragma once
#include "Entity.h"
class EnemyEntity :
    public Entity
{
private:
    std::string gfxName;
    float movementTick = 0.1f;
    Vector2 startPos;
    Vector2 endPos= Vector2(800,0);
public:
    EnemyEntity(std::string name);
    Vector2 lerp(float v1, float v2, float t);
    void EnemyMovement();


    virtual Vector2 GetPlayerPos() override { return Vector2(0.0f, 0.0f); }
    virtual bool ScreenTrigger() override { return false; }
    virtual Vector2 getEntityPosition() override { return e_entityPosition; }
    virtual Side GetSide() override { return Side::eEnemy; }
    virtual Type GetType() override { return Type::eEnemy; }
    virtual float GetSpeed() override { return 0.0f; }
    virtual void Update(World& world) override final;
};