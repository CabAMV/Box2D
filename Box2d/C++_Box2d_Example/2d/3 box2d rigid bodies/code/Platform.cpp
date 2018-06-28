#pragma once
#include "Platform.hpp"


Platform::Platform(Scene & scene) :GameObject(scene)
{
	tag = "Platform";

	isGoingUp = false;

	b2BodyDef platform_definition;

	platform_definition.type = b2_kinematicBody;
	platform_definition.position.Set(650, 225);   // Posición inicial absoluta

	platform_body = scene.getPhysicsWorld().CreateBody(&platform_definition);

	// Se añande una fixture al body:

	b2PolygonShape platform_shape;

	platform_shape.SetAsBox(50, 10);

	b2FixtureDef platform_fixture;

	platform_fixture.shape = &platform_shape;
	platform_fixture.density = 1.0f;
	platform_fixture.restitution = 0.50f;
	platform_fixture.friction = 0.50f;

	platform_body->CreateFixture(&platform_fixture);


	platform_body->SetUserData(this);



}


void Platform::update()
{
	if (platform_body->GetPosition().y >= 550 && isGoingUp) 
	{
		platform_body->SetLinearVelocity(b2Vec2(0, 0));
		isGoingUp = false;
	
	}



}

void Platform::startCollision()
{
	if (platform_body->GetPosition().y <= 550) 
	{
		platform_body->SetLinearVelocity(b2Vec2(0, 20));
		isGoingUp = true;
	}


}

string Platform::getTag()
{
	return tag;
}

