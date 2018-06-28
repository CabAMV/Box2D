#pragma once

#include <Box2D/Box2D.h>
#include <memory>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

using namespace sf;
using namespace std;


	class GameObject;

	class Scene
	{
	protected:
		b2World phxWorld;

		map< string, shared_ptr< GameObject > > game_objects;

	
	public:
		Scene(b2Vec2 gravity) :phxWorld(gravity) 
		{
		
		}

		void add_game_object(const string & name, shared_ptr< GameObject > & game_object)
		{
			game_objects[name] = game_object;
		}

		b2World & getPhysicsWorld()
		{
			return phxWorld;
		}

		GameObject * get_game_object(const string & name)
		{
			
			if (game_objects.count(name))
				return  game_objects[name].get();
			else
				return NULL;

			// SI LO ENCUENTRA RETORNA UN PUNTERO O NULL EN OTRO CASO
		}

		virtual void update(float deltaTime)
		{
			phxWorld.Step(deltaTime,8,4);
		}

		virtual void render(RenderWindow & renderer)
		{

		}

	};

