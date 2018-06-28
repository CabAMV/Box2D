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

	class Vehicle : public GameObject
	{
	private:
		b2RevoluteJoint* wheel1_joint;
		b2RevoluteJoint* wheel2_joint;
		
		int direction = 0;
		float speed = 20;




	public:
		Vehicle(Scene & scene);

		void update()override;

		b2Body * eje_body;

		void startCollision()override {}

		string getTag()override;

	};
