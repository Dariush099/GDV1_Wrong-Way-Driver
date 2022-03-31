
#pragma once

#include "math.hpp"

static float PLAYER_POS = -17.0f;
const int NUMBER_OF_BLOCKS = 22;
const int NUMBER_OF_CARS = 6;

struct SBlockList
{
	float position[3];
};

struct SCarList
{
	float position[3];
};

static SBlockList BLOCK_POSITION[] = 
{

	// left barrier
	{-20.0f, 18.0f, 0.0f},
	{-20.0f, 14.0f, 0.0f},
	{-20.0f, 10.0f, 0.0f},
	{-20.0f, 6.0f, 0.0f},
	{-20.0f, 2.0f, 0.0f},
	{-20.0f, -2.0f, 0.0f},
	{-20.0f, -6.0f, 0.0f},
	{-20.0f, -10.0f, 0.0f},
	{-20.0f, -14.0f, 0.0f},
	{-20.0f, -18.0f, 0.0f},
	{-20.0f, -22.0f, 0.0f},

	// right barrier

	{20.0f, 18.0f, 0.0f},
	{20.0f, 14.0f, 0.0f},
	{20.0f, 10.0f, 0.0f},
	{20.0f, 6.0f, 0.0f},
	{20.0f, 2.0f, 0.0f},
	{20.0f, -2.0f, 0.0f},
	{20.0f, -6.0f, 0.0f},
	{20.0f, -10.0f, 0.0f},
	{20.0f, -14.0f, 0.0f},
	{20.0f, -18.0f, 0.0f},
	{20.0f, -22.0f, 0.0f},
};

static SCarList CAR_POSITION[] =
{
	// Cars Positions
	{GetRandom(-20.0f, 20.0f), 20.0f, 0.0f},
	{GetRandom(-20.0f, 20.0f), 25.0f, 0.0f},
	{GetRandom(-20.0f, 20.0f), 30.0f, 0.0f},
	{GetRandom(-20.0f, 20.0f), 35.0f, 0.0f},
	{GetRandom(-20.0f, 20.0f), 40.0f, 0.0f},
	{GetRandom(-20.0f, 20.0f), 45.0f, 0.0f},
	//{GetRandom(-20.0f, 20.0f), 50.0f, 0.0f},
	//{GetRandom(-20.0f, 20.0f), 55.0f, 0.0f},
};
