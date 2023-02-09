#pragma once
#include "Entity.h"
class PlayerEntity :
    public Entity
{
private:
    std::string gfxName;
    Vector2 vecPosition;
    bool triggerScreen=false;
    bool leftValue{ false }, upValue{ false }, rightValue{ false }, downValue{ false };

    const HAPI_TKeyboardData& keyPressed = HAPI.GetKeyboardData();
    float xIncrement{ 0 }, yIncrement{ 0 };
    float ControllerTimer;
public:

    PlayerEntity(std::string name);
   /* ~PlayerEntity();*/
    
    

    //void setPlayerPosition(Vector2 targetVec);
    virtual Vector2 getEntityPosition()override { return e_entityPosition; }
    virtual Vector2 GetPlayerPos() override final{ return Vector2(vecPosition); }
    virtual bool ScreenTrigger() override { return triggerScreen; }
    //virtual bool PressShoot();
    virtual Side GetSide() override { return Side::ePlayer; }
    virtual Type GetType() override { return Type::ePlayer; }
    virtual float GetSpeed() override { return 0.0f; }
    virtual void Update(World &world) override final;
    void InputMovement(const HAPI_TKeyboardData& keyPressed, const HAPI_TControllerData& data);
    
    
    //Type GetType() const { return Type::ePlayer; }
};

