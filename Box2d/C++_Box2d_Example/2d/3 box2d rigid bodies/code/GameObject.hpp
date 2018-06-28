#pragma once

#include <Box2D/Box2D.h>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Scene.hpp"

using namespace sf;
using namespace std;

	class Scene;

	class GameObject
	{
	protected:
		Scene & scene;
		map< string, b2Body * > bodies;
		map< string, b2Joint * > joints;
		map< string, shared_ptr< sf::Shape > > gfxShapes;

		string tag = "";

	public:
		GameObject(Scene & scene) : scene(scene)
		{
		}

		void virtual update() = 0;

		void apply_force()
		{
		}

		void virtual render(RenderWindow & window);

		inline Vector2f box2d_position_to_sfml_position(const b2Vec2 & box2d_position, float window_height)
		{
			return Vector2f(box2d_position.x, window_height - box2d_position.y);
		}
		void virtual startCollision() = 0;
		string virtual getTag() = 0;

	};
