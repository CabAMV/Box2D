#pragma once


#include "Vehicle.hpp"

Vehicle::Vehicle(Scene & scene) :GameObject(scene)
{

	tag = "Vehicle";

	// rueda 1

	b2BodyDef wheel1_definition;

	wheel1_definition.type = b2_dynamicBody;
	wheel1_definition.position.Set(1100, 300);           // Posición inicial absoluta

	b2Body * wheel1_body = scene.getPhysicsWorld().CreateBody(&wheel1_definition);

	// Se añande una fixture al body:

	b2CircleShape wheel1_shape;

	wheel1_shape.m_radius = 5.f;

	b2FixtureDef wheel1_fixture;

	wheel1_fixture.shape = &wheel1_shape;
	wheel1_fixture.density = 1.0f;
	wheel1_fixture.restitution = 0.75f;
	wheel1_fixture.friction = 0.5f;

	wheel1_body->CreateFixture(&wheel1_fixture);


	// rueda 2

	b2BodyDef wheel2_definition;

	wheel2_definition.type = b2_dynamicBody;
	wheel2_definition.position.Set(1125, 300);           // Posición inicial absoluta

	b2Body * wheel2_body = scene.getPhysicsWorld().CreateBody(&wheel2_definition);

	// Se añande una fixture al body:

	b2CircleShape wheel2_shape;

	wheel2_shape.m_radius = 5.f;

	b2FixtureDef wheel2_fixture;

	wheel2_fixture.shape = &wheel2_shape;
	wheel2_fixture.density = 1.0f;
	wheel2_fixture.restitution = 0.75f;
	wheel2_fixture.friction = 0.5f;

	wheel2_body->CreateFixture(&wheel2_fixture);


	//eje de union

	b2BodyDef eje_definition;

	eje_definition.type = b2_dynamicBody;
	eje_definition.position.Set(1112, 307);   // Posición inicial absoluta

	eje_body = scene.getPhysicsWorld().CreateBody(&eje_definition);

	// Se añande una fixture al body:

	b2PolygonShape eje_shape;

	eje_shape.SetAsBox(15, 5);

	b2FixtureDef eje_fixture;

	eje_fixture.shape = &eje_shape;
	eje_fixture.density = 3.0f;
	eje_fixture.restitution = 0.50f;
	eje_fixture.friction = 0.50f;

	eje_body->CreateFixture(&eje_fixture);

	//revolute joints
	b2RevoluteJointDef wheel1_jointDef;
	wheel1_jointDef.Initialize(eje_body, wheel1_body, wheel1_body->GetWorldCenter());
	wheel1_jointDef.enableMotor = true;
	wheel1_jointDef.maxMotorTorque = 100000;
	wheel1_jointDef.motorSpeed = 0;
	wheel1_joint = (b2RevoluteJoint*)scene.getPhysicsWorld().CreateJoint(&wheel1_jointDef);

	b2RevoluteJointDef wheel2_jointDef;
	wheel2_jointDef.Initialize(eje_body, wheel2_body, wheel2_body->GetWorldCenter());
	wheel2_jointDef.enableMotor = true;
	wheel2_jointDef.maxMotorTorque = 10000;
	wheel2_jointDef.motorSpeed = 0;
	wheel2_joint = (b2RevoluteJoint*)scene.getPhysicsWorld().CreateJoint(&wheel2_jointDef);

	//basket

	b2BodyDef basket_definition;

	basket_definition.type = b2_dynamicBody;
	basket_definition.position.Set(1112, 317);   // Posición inicial absoluta
	//basket_definition.angle = 0.25f;
	b2Body * basket_body = scene.getPhysicsWorld().CreateBody(&basket_definition);

	b2PolygonShape basket1_shape;
	b2PolygonShape basket2_shape;
	b2PolygonShape basket3_shape;


	basket1_shape.SetAsBox(15, 3);
	basket2_shape.SetAsBox(3, 7, b2Vec2(11, 5), 0);
	basket3_shape.SetAsBox(3, 7, b2Vec2(-11, 5), 0);

	b2FixtureDef basket1_fixture;

	basket1_fixture.shape = &basket1_shape;
	basket1_fixture.density = 1.5f;
	basket1_fixture.restitution = 0.50f;
	basket1_fixture.friction = 0.50f;

	b2FixtureDef basket2_fixture;

	basket2_fixture.shape = &basket2_shape;
	basket2_fixture.density = 1.5f;
	basket2_fixture.restitution = 0.50f;
	basket2_fixture.friction = 0.50f;

	b2FixtureDef basket3_fixture;

	basket3_fixture.shape = &basket3_shape;
	basket3_fixture.density = 1.5f;
	basket3_fixture.restitution = 0.50f;
	basket3_fixture.friction = 0.50f;

	basket_body->CreateFixture(&basket1_fixture);
	basket_body->CreateFixture(&basket2_fixture);
	basket_body->CreateFixture(&basket3_fixture);

	// visagra
	
	b2RevoluteJointDef jointDef;
	jointDef.Initialize(eje_body, basket_body, basket_body->GetWorldCenter() + b2Vec2(15, -7));
	jointDef.enableLimit = true;
	jointDef.lowerAngle = -45;
	jointDef.upperAngle = 0;
	jointDef.collideConnected = true;
	b2RevoluteJoint* joint = (b2RevoluteJoint*)scene.getPhysicsWorld().CreateJoint(&jointDef);

	eje_body->SetUserData(this);
	wheel1_body->SetUserData(this);


}


void Vehicle::update()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
	{
		wheel1_joint->SetMaxMotorTorque(100000);
		wheel2_joint->SetMaxMotorTorque(100000);
		wheel1_joint->SetMotorSpeed(speed);
		wheel2_joint->SetMotorSpeed(speed);
		direction = 1;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		wheel1_joint->SetMaxMotorTorque(100000);
		wheel2_joint->SetMaxMotorTorque(100000);
		wheel1_joint->SetMotorSpeed(-speed);
		wheel2_joint->SetMotorSpeed(-speed);
		direction = -1;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		wheel1_joint->SetMaxMotorTorque(0);
		wheel2_joint->SetMaxMotorTorque(0);
		wheel1_joint->SetMotorSpeed(0);
		wheel2_joint->SetMotorSpeed(0);
		eje_body->SetLinearVelocity(-eje_body->GetLinearVelocity());

	}
	else 
	{
		wheel1_joint->SetMaxMotorTorque(0);
		wheel2_joint->SetMaxMotorTorque(0);
		wheel1_joint->SetMotorSpeed(0);
		wheel2_joint->SetMotorSpeed(0);
		//eje_body->SetLinearVelocity(-eje_body->GetLinearVelocity());


	}


}

string Vehicle::getTag()
{
	return tag;
}


