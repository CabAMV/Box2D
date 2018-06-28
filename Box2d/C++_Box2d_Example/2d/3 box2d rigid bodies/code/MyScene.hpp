#pragma once

#include "Scene.hpp"
#include "Floor.hpp"
#include "Vehicle.hpp"
#include "YBox.hpp"
#include "GameObject.hpp"
#include "Platform.hpp"
#include "MyContactListener.hpp"


using namespace sf;
using namespace std;



	class MyScene:public Scene
	{
	public:
		MyContactListener myContactListenerInstance;

		MyScene(b2Vec2 gravity) :Scene(gravity)
		{
			
			//scene add objects
			add_game_object("Floor", shared_ptr< GameObject >(new Floor(*this)));
			add_game_object("Vehicle", shared_ptr< GameObject >(new Vehicle(*this)));
			add_game_object("Platform", shared_ptr< GameObject >(new Platform(*this)));
			add_game_object("Ybox", shared_ptr< GameObject >(new YBox(*this)));


			getPhysicsWorld().SetContactListener(&myContactListenerInstance);
			//getPhysicsWorld().SetContactListener(&platformListener);



		}

		void update(float deltaTime)override;

		void render(RenderWindow & renderer)override;


	};

