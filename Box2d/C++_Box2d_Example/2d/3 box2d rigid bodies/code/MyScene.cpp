#pragma once

#include "MyScene.hpp"

void MyScene::update(float deltaTime)
{
	Scene::update(deltaTime);
	for (auto it = game_objects.begin(); it != game_objects.end(); it++) 
	{
		auto key = it->first;
		game_objects[key]->update();
	}
}



void MyScene::render(RenderWindow & renderer)
{
	for (auto it = game_objects.begin(); it != game_objects.end(); it++)
	{
		auto key = it->first;
		game_objects[key]->render(renderer);
	}
}