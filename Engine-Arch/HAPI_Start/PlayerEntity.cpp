#include "PlayerEntity.h"

PlayerEntity::PlayerEntity(std::string name)
{
	gfxName = name;
	e_isAlive = true;
	e_entityHealth = 100;
	e_entityPosition = Vector2(512, 384);
	ControllerTimer =0.f;
	
}






void PlayerEntity::Update(World& world)
{
	const HAPI_TControllerData& data = HAPI.GetControllerData(0);

	ControllerTimer += HAPI.GetTime();
	
	InputMovement(keyPressed, data);
	
}
void PlayerEntity::InputMovement(const HAPI_TKeyboardData& keyPressed, const HAPI_TControllerData& data)
{
	if (ControllerTimer < 5.0f) 
	{
		ControllerTimer = 0.0f;
		if (data.isAttached) 
		{

			// Controller Inputs
			if (data.digitalButtons[HK_DIGITAL_DPAD_UP])
			{
				upValue = true;
			}
			if (data.digitalButtons[HK_DIGITAL_DPAD_DOWN])
			{
				downValue = true;

			}
			if (data.digitalButtons[HK_DIGITAL_DPAD_RIGHT])
			{
				rightValue = true;

			}
			if (data.digitalButtons[HK_DIGITAL_DPAD_LEFT])
			{
				leftValue = true;

			}

		}
	}

	if (keyPressed.scanCode['G']) {
		triggerScreen = true;
	}
	else {
		triggerScreen = false;
	}

	//if(keyPressed.scanCode[HK_SPACE])
	{
		// Shoot Bullet
	}
	// Up
	xIncrement = 0;
	yIncrement = 0;
	if (keyPressed.scanCode['W'] || keyPressed.scanCode[HK_UP] || upValue) {
		yIncrement = -1;
		

	}upValue = false;
	// Down
	if (keyPressed.scanCode['S'] || keyPressed.scanCode[HK_DOWN] || downValue) {
		yIncrement = 1;
	}downValue = false;
	// Left
	if (keyPressed.scanCode['A'] || keyPressed.scanCode[HK_LEFT] || leftValue) {
		xIncrement = -1;
	}leftValue = false;
	// Right
	if (keyPressed.scanCode['D'] || keyPressed.scanCode[HK_RIGHT] || rightValue) {
		xIncrement = 1;
	}rightValue = false;

	if (xIncrement != 0 && yIncrement != 0)
	{
		yIncrement *= (float)0.707;
		xIncrement *= (float)0.707;
	}

	e_entityPosition.x += xIncrement;
	e_entityPosition.y += yIncrement;

	
}