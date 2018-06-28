#pragma once

#include <SfML/Graphics.hpp>
#include <stdio.h>
#include "Particle.hpp"

using namespace sf;
using namespace std;

class ParticleSystem
{
private:
	vector<Particle> dots;
	vector<Vertex> specks;
	int num = 1000;

public:
	ParticleSystem()
	{
		generateParticles(100,100,1,sf::Color::White);
	}

	void generateParticles(float x, float y, size_t size, sf::Color color);

	void render(RenderWindow & window);

	void update();

	vector<Particle> generateDots(float x, float y, size_t num);
	vector<Vertex> generateSpecks(vector<Particle> d, sf::Color color);





};
