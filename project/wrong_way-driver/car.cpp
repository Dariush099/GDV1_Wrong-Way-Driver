

#include "car.hpp"
#include <iostream>

SCar::SCar()
{

}

SCar::SCar(float position[3])
{
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->position[2] = position[2];
	this->speed = 0.1f;
}

void SCar::updateWorldMatrix()
{
	gfx::GetTranslationMatrix(
		this->position[0],
		this->position[1],
		this->position[2],
		this->worldMatrix
	);
}

void SCar::move()
{
	this->position[1] -= this->speed;
}

bool SCar::collision(SPlayer& player)
{
	float diffX = this->position[0] - player.position[0];
	float diffy = player.position[1] - this->position[1];
	float OffsetY = 2.0f + 4.0f / 2;
	float OffsetX = 1.0f + 2.0f / 2;

	if (fabs(diffX) <= OffsetX && std::fabs(diffy) <= OffsetY)
	{
		return true;
	}
	else return false;
}
