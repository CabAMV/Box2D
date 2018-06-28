#pragma once
#include "Floor.hpp"


Floor::Floor(Scene & scene) :GameObject(scene)
{
	tag = "Floor";
	particleRED= ParticleSystem();
	particleGREEN = ParticleSystem();
	particleBLUE = ParticleSystem();
	particleYELLOW = ParticleSystem();
	counter = 0;

	// Se crea el body a partir de una definición de sus características:

	b2BodyDef body_definition;

	body_definition.type = b2_staticBody;
	body_definition.position.Set(0.f, 50.f);                                       // Posición inicial absoluta

	b2Body * body = scene.getPhysicsWorld().CreateBody(&body_definition);

	// Se añande una fixture al body:

	b2EdgeShape body_shape;

	body_shape.Set(b2Vec2(1280, 200), b2Vec2(1050, 200));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture;

	body_fixture.shape = &body_shape;

	body->CreateFixture(&body_fixture);




	b2EdgeShape body_shape1;

	body_shape1.Set(b2Vec2(1050, 200), b2Vec2(950, 162));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture1;

	body_fixture1.shape = &body_shape1;

	body->CreateFixture(&body_fixture1);


	b2EdgeShape body_shape2;

	body_shape2.Set(b2Vec2(950, 162), b2Vec2(800, 150));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture2;

	body_fixture2.shape = &body_shape2;

	body->CreateFixture(&body_fixture2);


	b2EdgeShape body_shape3;

	body_shape3.Set(b2Vec2(800, 150), b2Vec2(750, 175));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture3;

	body_fixture3.shape = &body_shape3;

	body->CreateFixture(&body_fixture3);


	b2EdgeShape body_shape4;

	body_shape4.Set(b2Vec2(600, 190), b2Vec2(0, 190));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture4;

	body_fixture4.shape = &body_shape4;

	body->CreateFixture(&body_fixture4);


	b2EdgeShape body_shape5;

	body_shape5.Set(b2Vec2(700, 510), b2Vec2(1000, 510));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture5;

	body_fixture5.shape = &body_shape5;

	body->CreateFixture(&body_fixture5);



	b2BodyDef body_definitioncollision;

	body_definitioncollision.type = b2_staticBody;
	body_definitioncollision.position.Set(0.f, 50.f);                                       // Posición inicial absoluta

	b2Body * bodyCollider = scene.getPhysicsWorld().CreateBody(&body_definitioncollision);


	b2EdgeShape body_shape6;

	body_shape6.Set(b2Vec2(1000, 510), b2Vec2(1100, 400));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture6;

	body_fixture6.shape = &body_shape6;

	bodyCollider->CreateFixture(&body_fixture6);


	b2EdgeShape body_shape7;

	body_shape7.Set(b2Vec2(1100, 400), b2Vec2(1200, 510));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef body_fixture7;

	body_fixture7.shape = &body_shape7;

	bodyCollider->CreateFixture(&body_fixture7);

	bodyCollider->SetUserData(this);

}


void Floor::update()
{
	 particleRED.update();
	 particleGREEN.update();
	 particleBLUE.update();
	 particleYELLOW.update();

	 if (Mouse::isButtonPressed(Mouse::Left))
		 startCollision();
}

string Floor::getTag()
{
	return tag;
}

void Floor::startCollision()
{	
	//int r=rand() % 4;
	switch (counter)
	{
	case 0:
		particleRED.generateParticles(100, 100, 100,sf::Color::Red);
		break;
	case 1:
		particleGREEN.generateParticles(1180, 100, 100,sf::Color::Green);
		break;
	case 2:
		particleBLUE.generateParticles(100, 600, 100, sf::Color::White);
		break;
	case 3:
		particleYELLOW.generateParticles(1180, 600, 100, sf::Color::Magenta);
		break;

	default:
		break;
	}

	counter++;
	if (counter > 3)
		counter = 0;
	//particleRED.generateParticles(100,100,10000);
	//particleGREEN.generateParticles(100,1000, 10000);
	//particleBLUE.generateParticles(1000, 100, 10000);
	//particleYELLOW.generateParticles(1000, 1000, 10000);
}

void Floor::render(RenderWindow & window)
{
	GameObject::render(window);

	particleRED.render(window);
	particleGREEN.render(window);
	particleBLUE.render(window);
	particleYELLOW.render(window);

}
