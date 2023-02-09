#pragma once
#include<string>
#include <HAPI_lib.h>
#include <unordered_map>




class Audio
{
private:
	

public:
	bool LoadSound(const std::string& songName);
	void PlaySound(const std::string& songName, const float &volume, const bool &looping);

};

