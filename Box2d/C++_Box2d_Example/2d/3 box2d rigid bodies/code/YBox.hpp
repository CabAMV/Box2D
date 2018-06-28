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

class YBox : public GameObject
{
private:

	b2RevoluteJoint* joint;

public:
	YBox(Scene & scene);

	void update()override;

	void createBalls();

	void rotateY();

	void startCollision()override;

	string getTag()override;

};