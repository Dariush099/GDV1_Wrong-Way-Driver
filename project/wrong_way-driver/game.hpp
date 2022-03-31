
#pragma once

#include "block.hpp"
#include "player.hpp"
#include "car.hpp"
#include "data.hpp"
#include "key.hpp"

#include  "yoshix_fix_function.h"

#include <iostream>
#include <array>
#include <tuple>
#include <vector>

using namespace gfx;

class CGame
{
public:
	CGame();

	SCar getCar(int i);
	SBlock getBlock(int i);
	SPlayer getPlayer();
	void onUpdate(EKey key);
	int getCollision();

private:
	void initGame();

private:
	SPlayer player;
	SBlock Blocks[NUMBER_OF_BLOCKS];
	SCar Cars[NUMBER_OF_CARS];
	int crashedCarsCounter;

};