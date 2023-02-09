#include "Sound.h"
#include <HAPI_lib.h>

Sound::Sound()
{
	s_Looping= false;
	s_Volume = 1.0f;
	s_Pan = 0.0f;
	s_Pitch = 1.0f;
}
Sound::~Sound() 
{
	
}
bool Sound::Load(const std::string&filePath) {

	if (!HAPI.LoadSound("Audio/" + filePath+".wav"))
	{
		std::cerr << "Could Not Load: " + filePath;
		return false;
	}

	return true;
}
bool Sound::Play(const std::string& soundName, bool defaultSound, const bool &isLooping,
	const float &volumeValue,const float &panValue,const float &pitchValue) {
	
	
	if (defaultSound) {
		//int InstanceID = 1;
		HAPISPACE::HAPI_TSoundOptions options(s_Volume,s_Looping,s_Pan,s_Pitch);

		if (!HAPI.PlaySound("Audio/" + soundName, options))
		{
			std::cerr << "Could not play the sound: " + soundName;
			return false;
		}
		return true;
	}

	else {
		HAPISPACE::HAPI_TSoundOptions options(volumeValue, isLooping, panValue, pitchValue);

		if (!HAPI.PlaySound("Audio/" + soundName, options))
		{
			std::cerr << "Could not play the sound: " + soundName;
			return false;
		}
		return true;
	}
	

}