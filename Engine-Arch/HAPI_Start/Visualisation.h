#pragma once
#include <unordered_map>

#include <HAPI_lib.h>

class Sprite;

class Rectangle;
class Vector2;
using namespace HAPISPACE;
class Visualisation
{
private:
	BYTE* m_screen{ nullptr };
	std::unordered_map<std::string,Sprite*> m_spriteMap;
	

public:
	~Visualisation();
	Visualisation(BYTE* screenPtr);

	bool ScreenShot(int width, int height);
	void ClearScreen(int width, int height);

	bool CreateSprite(std::string spriteName, bool hasAlpha, const std::string &filename);
	void DrawSprite(const std::string &spriteName, const Rectangle& screenBox, const Vector2 vector, int frameNumber=0);
	
	int GetSpriteWidth(const std::string& spriteName);
	int GetSpriteHeight(const std::string& spriteName);

	
};

