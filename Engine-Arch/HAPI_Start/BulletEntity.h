#pragma once
#include"Entity.h" 
class BulletEntity : public Entity {
private:
	std::string b_gfxName;
	float b_speed;
public:
	BulletEntity(std::string gfxName);
	~BulletEntity();
	void Movement();

	virtual Vector2 GetPlayerPos() override { return Vector2(0.0f, 0.0f); }
	virtual void Update(World& world) override final;
	virtual Vector2 getEntityPosition() override { return Vector2(0, 0); }
	virtual float GetSpeed() override { return b_speed; }
	virtual Side GetSide() override{ return Side::eNeutral; }
	virtual Type GetType() override { return Type::eExplosion; }
	virtual bool ScreenTrigger() override { return false; };
};