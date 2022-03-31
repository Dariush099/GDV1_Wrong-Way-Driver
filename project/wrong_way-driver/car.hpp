
#pragma once

#include "yoshix_fix_function.h"
#include "player.hpp"


using namespace gfx;

struct SCar
{
	SCar();
	SCar(float position[3]);

	void move();
	void updateWorldMatrix();
	bool collision(SPlayer& player);

	float position[3];
	float worldMatrix[16];
	float speed;
};

