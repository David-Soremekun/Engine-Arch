#include "Sound.h"
#include "SoundManager.h"

SoundManager::~SoundManager()
{
    
}

bool SoundManager::LoadSound(const std::string &fileName,const std::string &soundName)
{
    Sound* newSound = new Sound();
    if (newSound->Load(fileName))
    {
        delete newSound;
        return false;
    }

    m_soundMap[soundName] = newSound;

    return true;
}

bool SoundManager::PlaySound(const std::string&soundName,bool defaultOption, const bool& looping,
    const float& volumeVal, const float& panVal, const float& pitchVal)
{

    //m_soundMap.find(soundName) == m_soundMap.end()
        


    if(!m_soundMap[soundName]->Play(soundName,defaultOption,looping,volumeVal,panVal,pitchVal))
        return false;
    return true;
}
