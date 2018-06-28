#pragma once

#include <Box2D/Box2D.h>
#include <memory>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Scene.hpp"
#include "GameObject.hpp"

using namespace sf;
using namespace std;

class Platform : public GameObject
{
private:
	b2Body * platform_body;
	bool isGoingUp;

public:
	Platform(Scene & scene);

	void update()override;

	void startCollision()override;

	string getTag()override;
};