#pragma once

#include <Box2D/Box2D.h>
#include <memory>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ParticleSystem.hpp"

#include "Scene.hpp"
#include "GameObject.hpp"

using namespace sf;
using namespace std;

	class Floor : public GameObject
	{
	private:

		ParticleSystem particleRED;
		ParticleSystem particleGREEN;
		ParticleSystem particleBLUE;
		ParticleSystem particleYELLOW;

		int counter;

	public:

		Floor(Scene & scene);

		void update()override;

		void startCollision()override;

		void render(RenderWindow & window)override;

		string getTag()override;

	};
