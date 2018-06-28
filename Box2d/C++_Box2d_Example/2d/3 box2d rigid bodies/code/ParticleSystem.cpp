#include "ParticleSystem.hpp"

vector<Particle> ParticleSystem::generateDots(float x,float y,size_t num)
{
	vector<Particle> parts;
	float radius, theta, vX, vY;

	for (size_t i = 0; i<num; i++)
	{
		Particle temp;

		radius = rand() % 1000;
		radius = (radius / 1000) + .005;

		theta = rand() % 10000;

		vX = radius*cos(theta);
		vY = radius*sin(theta);

		temp.vel = Vector2f(vX, vY);
		temp.pos = Vector2f(x, y);

		parts.push_back(temp);

	}

	return parts;
}


vector<Vertex> ParticleSystem::generateSpecks(vector<Particle> d, sf::Color color)
{
	vector<Vertex> verts;

	for (size_t i = 0; i<d.size(); i++)
	{
		Vertex temp;
		temp.position = d[i].pos;
		temp.color = color;

		verts.push_back(temp);
	}

	return verts;
}

void ParticleSystem::generateParticles(float x, float y, size_t size, sf::Color color)
{
	dots.clear();
	specks.clear();

	dots = generateDots(x,y,size);
	specks = generateSpecks(dots, color);

}

void ParticleSystem::render(RenderWindow & window)
{
	window.draw(&specks[0], specks.size(), Points);

}

void ParticleSystem::update()
{

	for (size_t i = 0; i<dots.size(); i++)
	{
		dots[i].update();
		specks[i].position = dots[i].pos;
	}
	//if (Mouse::isButtonPressed(Mouse::Left)) 
	//{
	//	generateParticles(10,10,10000);
	//}

}

