#pragma once
#include "YBox.hpp"


YBox::YBox(Scene & scene) :GameObject(scene)
{
	tag = "YBox";

	//pilar
	b2BodyDef pilar_definition;

	pilar_definition.type = b2_staticBody;
	pilar_definition.position.Set(100, 300);   // Posición inicial absoluta

	b2Body * pilar_body = scene.getPhysicsWorld().CreateBody(&pilar_definition);

	// Se añande una fixture al body:

	b2PolygonShape pilar_shape;

	pilar_shape.SetAsBox(7, 60);

	b2FixtureDef pilar_fixture;

	pilar_fixture.shape = &pilar_shape;
	pilar_fixture.density = 1.0f;
	pilar_fixture.restitution = 0.50f;
	pilar_fixture.friction = 0.50f;
	
	b2FixtureDef trigger_fixture;

	b2PolygonShape Trigger_shape;
	Trigger_shape.SetAsBox(10, 10, b2Vec2(75, -60),0);
	Trigger_shape.m_radius = 30;
	trigger_fixture.shape = &Trigger_shape;
	trigger_fixture.isSensor = true;


	pilar_body->CreateFixture(&pilar_fixture);
	pilar_body->CreateFixture(&trigger_fixture);

	pilar_body->SetUserData(this);


	//yleft
	b2BodyDef Y_definition;

	Y_definition.type = b2_dynamicBody;
	Y_definition.position.Set(100, 312);   // Posición inicial absoluta

	b2Body * Y_body = scene.getPhysicsWorld().CreateBody(&Y_definition);

	// Se añande una fixture al body:

	b2PolygonShape yleft_shape;
	b2PolygonShape yright_shape;


	yleft_shape.SetAsBox(7, 20, b2Vec2(20, 68), -45);
	yright_shape.SetAsBox(7, 20, b2Vec2(-20, 68), 45);


	b2FixtureDef yleft_fixture;

	yleft_fixture.shape = &yleft_shape;
	yleft_fixture.density = 1.0f;
	yleft_fixture.restitution = 0.50f;
	yleft_fixture.friction = 0.50f;

	b2FixtureDef yright_fixture;

	yright_fixture.shape = &yright_shape;
	yright_fixture.density = 1.0f;
	yright_fixture.restitution = 0.50f;
	yright_fixture.friction = 0.50f;

	Y_body->CreateFixture(&yleft_fixture);
	Y_body->CreateFixture(&yright_fixture);



	//joint

	b2RevoluteJointDef jointDef;
	jointDef.Initialize(pilar_body, Y_body, pilar_body->GetWorldCenter() + b2Vec2(0, 68));
	jointDef.enableLimit = false;
	jointDef.enableMotor = true;
	jointDef.maxMotorTorque = 1000000;
	jointDef.motorSpeed = 0;
	jointDef.collideConnected = true;
	joint = (b2RevoluteJoint*)scene.getPhysicsWorld().CreateJoint(&jointDef);

	for (size_t i = 0; i < 10; i++) 
	{
		createBalls();
	}



}


void YBox::update()
{



}

void YBox::createBalls()
{
	b2BodyDef circle_definition;

	circle_definition.type = b2_dynamicBody;
	circle_definition.position.Set(100, 400);           // Posición inicial absoluta

	b2Body * circle = scene.getPhysicsWorld().CreateBody(&circle_definition);

	// Se añande una fixture al body:

	b2CircleShape circle_shape;

	circle_shape.m_radius = 3.f;

	b2FixtureDef circle_fixture;

	circle_fixture.shape = &circle_shape;
	circle_fixture.density = 5.00f;
	circle_fixture.restitution = 0;
	circle_fixture.friction = 0.50f;


	circle->CreateFixture(&circle_fixture);

	circle->SetUserData(this);

}

void YBox::rotateY()
{
	joint->SetMotorSpeed(-10000); 

}

void YBox::startCollision()
{
	rotateY();

}

string YBox::getTag()
{
	return tag;
}
