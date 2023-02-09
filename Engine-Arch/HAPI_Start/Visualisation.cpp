#include "Visualisation.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "Vector2.h"
#include <chrono>
#include <time.h>
#include <cassert>
Visualisation::~Visualisation()
{
    
}

Visualisation::Visualisation(BYTE* screenPtr)
{
    m_screen=screenPtr;
}

void Visualisation::DrawSprite(const std::string& spriteName, const Rectangle& screenBox, const Vector2 vector, int frameNumber)
{
    if(m_spriteMap.find(spriteName) == m_spriteMap.end())
        return;
    

    m_spriteMap[spriteName]->Draw(m_screen, screenBox,(int)vector.x, (int)vector.y, frameNumber);
}

int Visualisation::GetSpriteWidth(const std::string& spriteName)
{
    if (m_spriteMap.find(spriteName) == m_spriteMap.end())
        return -1;

    return m_spriteMap[spriteName]->Width();
}

int Visualisation::GetSpriteHeight(const std::string& spriteName)
{
    if(m_spriteMap.find(spriteName) == m_spriteMap.end())
        return -1;
    
    return m_spriteMap[spriteName]->Height();
}



bool Visualisation::CreateSprite(std::string spriteName, bool hasAlpha, const std::string& filename)
{
    Sprite* newSprite = new Sprite(hasAlpha);
    if (newSprite->Load(filename)) 
    {
        delete newSprite;
        return false;
    }

    m_spriteMap[spriteName] = newSprite;
     
    return true;
}

void Visualisation::ClearScreen(int width, int height)
{
    _ASSERT(m_screen != nullptr);

    BYTE* copyPointer = &m_screen[(width * height * 4) / 2];
    for (int i = 0; i < (width * height * 4) / 2; i += 4)
    {
        m_screen[(i)] = 0;
        m_screen[(i)+1] = 0;
        m_screen[(i)+2] = 0;
    }
    memcpy(copyPointer, m_screen, (height * width * 4) / 2);
}

bool Visualisation::ScreenShot(int width, int height)
{
    _ASSERT(m_screen != nullptr);

    int randNum = rand() % 8999+1000;
    std::string fileName = std::to_string(randNum);

    if (!HAPI.SaveImage(m_screen, width, height, "ScreenShots/" + fileName + ".jpg"))
    {
        std::cerr << "It failed to save";
        return false;
    }
    return true;
}
