
#pragma once
#include "yoshix_fix_function.h"

using namespace gfx;

struct SBlock
{
	SBlock();
	SBlock(float position[3]);

	float position[3];
	float worldMatrix[16];
};