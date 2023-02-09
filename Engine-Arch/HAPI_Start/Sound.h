#pragma once
#include <string>
class Sound 
{
private:
	bool s_Looping;
	float s_Volume;
	float s_Pan;
	float s_Pitch;


public:
	Sound();
	~Sound();
	bool Load(const std::string &filePath);
	bool Play(const std::string& soundName, bool defaultSound, const bool& isLooping,
		const float& volumeValue, const float& panValue, const float& pitchValue);

};

