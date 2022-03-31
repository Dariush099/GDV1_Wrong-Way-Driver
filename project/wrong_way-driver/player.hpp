
#pragma once

#include "yoshix_fix_function.h"
#include "key.hpp"

using namespace gfx;

struct SPlayer
{
	SPlayer();

	float worldMatrix[16];
	float position[3];
	float width;

	void move(EKey key, float leftbarrier, float rightbarrier);
	void updateWorldMatrix();

private:
	float speed;
};
