#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Scene.hpp"
#include "Vehicle.hpp"
#include "Platform.hpp"


using namespace sf;
using namespace std;

class PlatformContactListener : public b2ContactListener
{
public:
	PlatformContactListener()
	{
	}

	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact) {}

};