#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;
class Rectangle;
class Sprite
{
private:

	int m_width;
	int m_height;
	int m_alpha{ 0 };

	bool m_hasAlpha;
	
	BYTE* m_texture{ nullptr };
public:

	Sprite(bool Alpha);
	~Sprite();

	int Width() const { return m_width; }
	int Height() const  { return m_height; }

	bool Load(const std::string& sfilename);
	
	void Draw(BYTE* m_screen, const Rectangle& screenRect, int x, int y, int frameNumber = 0);
	void DrawTexture(BYTE* m_screen, int m_screenWidth, int m_posX, int m_posY);
	void BlitTransparency(BYTE* m_screen, int m_screenWidth, int m_posX, int m_posY, const Rectangle& SpriteBox);
};

