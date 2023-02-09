

#include <HAPI_lib.h>

#include <iostream>

#include "World.h"
// HAPI itself is wrapped in the HAPISPACE namespace


int width{ 1024 };
int height{ 768 };





void HAPI_Main()
{
	
	if (!HAPI.Initialise(width, height, "David Soremekun, HAPI HOUR "))
		return;

	World world;
	world.Run();

}

