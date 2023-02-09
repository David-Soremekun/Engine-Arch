#include "Sprite.h"
#include "Rectangle.h"
#include <random>

Sprite::Sprite(bool Alpha)
{
	m_hasAlpha = Alpha;
	
}
Sprite::~Sprite()
{
	delete m_texture;

}
bool Sprite::Load(const std::string& sfilename)
{
	if (!HAPI.LoadTexture("Data\\"+sfilename, &m_texture, m_width, m_height))
	{
		HAPI.LoadTexture("Data/Horrid_Pink.tga", &m_texture, m_width, m_height);
		HAPI.UserMessage("Could Not Load Texture", "Error");
		

	}
	return false;
}



void Sprite::Draw(BYTE* m_screen, const Rectangle& screenRect, int x, int y, int frameNumber)
{
	
	Rectangle clippedRect(0, m_width, 0, m_height);
	clippedRect.Translate(x, y);
	
	clippedRect.ClipTo(screenRect);

	clippedRect.Translate(-x, -y);
	
	screenRect.Width();

	if (x<0) {
		x = 0;
	}if (y < 0) {
		y = 0;
	}

	//std::cerr << "We got up to this point- Print Check";
	if (m_hasAlpha)
		BlitTransparency(m_screen, 1024, x, y, clippedRect);
	else
		DrawTexture(m_screen,1024,x,y);
	
}

void Sprite::DrawTexture(BYTE* m_screen, int m_screenWidth, int m_posX, int m_posY)
{
	int screenOffset = (m_posX + m_posY * m_screenWidth) * 4;
	int textureOffSet = 0;

	for (size_t x = 0; x < m_height; x++)
	{
		memcpy(m_screen + screenOffset, m_texture + textureOffSet, m_width * 4);
		screenOffset += m_screenWidth * 4;
		textureOffSet += m_width * 4;

	}
}

void Sprite::BlitTransparency(BYTE* m_screen, int m_screenWidth, int m_posX, int m_posY, const Rectangle& SpriteBox)
{
	int screenOffset = (m_posX + m_posY * m_screenWidth) * 4;
	int endOfLineOffsetScreen = (m_screenWidth - SpriteBox.Width()) * 4;
	int endOfLineOffsetTexture = (m_width - SpriteBox.Width()) * 4;
	int textureOffset = (SpriteBox.Left() + SpriteBox.Top() * m_width) * 4;


	for (int y = 0; y < SpriteBox.Height(); y++)
	{
		for (int x = 0; x < SpriteBox.Width(); x++)
		{

				BYTE texR = m_texture[textureOffset];
				BYTE texG = m_texture[textureOffset + 1];
				BYTE texB = m_texture[textureOffset + 2];
				BYTE texA = m_texture [textureOffset + 3];
				if (texA <= m_alpha)
				{
					texA = 0;
				}
				else if (texA - m_alpha > 255)
				{
					texA = 255;
				}
				else
				{
					texA = texA - m_alpha;
				}



				if (texR == 255 && texG == 255 && texB == 255) // dont draw white texels
				{
					texA = 0;
				}

				
				if (texA > 0)
				{
					if (texA == 255)
					{
						m_screen[screenOffset] = texR;
						m_screen[screenOffset + 1] = texG;
						m_screen[screenOffset + 2] = texB;
					}
					else
					{


						float ratio = texA / 255.0f;
						BYTE screenR = m_screen[screenOffset];
						BYTE screenG = m_screen[screenOffset + 1];
						BYTE screenB = m_screen[screenOffset + 2];


						BYTE finalR = (BYTE)(ratio * texR + (1.0f - ratio) * screenR);
						BYTE finalG = (BYTE)(ratio * texG + (1.0f - ratio) * screenG);
						BYTE finalB = (BYTE)(ratio * texB + (1.0f - ratio) * screenB);

						m_screen[screenOffset] = finalR;
						m_screen[screenOffset + 1] = finalG;
						m_screen[screenOffset + 2] = finalB;
					}
				}
			
			textureOffset += 4;
			screenOffset += 4;

		}

		screenOffset += endOfLineOffsetScreen;
		textureOffset += endOfLineOffsetTexture;
	}


}
