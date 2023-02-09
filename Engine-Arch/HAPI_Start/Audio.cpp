

#include "Audio.h"

#include <string>
#include <HAPI_lib.h>
using namespace HAPISPACE;


bool Audio::LoadSound(const std::string& songName)
{
	if (!HAPI.LoadSound("Audio/" + songName))
	{
		
		return false;
	}

	return true;
}

void Audio::PlaySound(const std::string& songName,const float &volume, const bool &looping)
{
	int InstanceID = 1;
	HAPI_TSoundOptions options(volume, looping);

	if (!HAPI.PlaySound("Audio/" + songName, options,InstanceID))
	{

	}

}