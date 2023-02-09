#pragma once
#include <unordered_map>
#include <string>
class Sound;
class SoundManager
{
private:
	std::unordered_map<std::string, Sound*> m_soundMap;
public:
	~SoundManager();
	bool LoadSound(const std::string& fileName, const std::string& soundName);
	bool PlaySound(const std::string& soundName,bool defaultOption, const bool& looping,
		const float& volumeVal, const float& panVal, const float& pitchVal);
};

