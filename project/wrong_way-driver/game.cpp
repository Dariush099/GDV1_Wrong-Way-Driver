
#include "game.hpp"

CGame::CGame()
{
	this->initGame();
	this->crashedCarsCounter = 0;
}

SCar CGame::getCar(int i)
{
	return this->Cars[i];
}

SBlock CGame::getBlock(int i)
{
	return this->Blocks[i];
}

SPlayer CGame::getPlayer()
{
	return this->player;
}

void CGame::initGame()
{
	this->player = SPlayer();

	// get positon from data.hpp
	for (int i = 0; i < NUMBER_OF_BLOCKS; i++)
	{
		Blocks[i] = SBlock(BLOCK_POSITION[i].position);		
	}
	
	for (int i = 0; i < NUMBER_OF_CARS; i++)
	{
		Cars[i] = SCar(CAR_POSITION[i].position);
	}
}

void CGame::onUpdate(EKey key)
{
	this->player.move(key, -17.0f, 17.0f);
	for (int i = 0; i < NUMBER_OF_CARS; i++)
	{
		Cars[i].move();
		if (Cars[i].collision(this->player) == true)
		{
			Cars[i].position[0] = GetRandom(-16.0, 16.0f);			// cars get random x position 
			Cars[i].position[1] = 20;				
			Cars[i].position[2] = NULL;
			Cars[i].speed += 0.01f;									// increase speed 
			this->crashedCarsCounter++;
		}
		if (Cars[i].position[1] < -20)
		{
			Cars[i].position[0] = GetRandom(-16.0, 16.0f);
			Cars[i].position[1] = 20;
			Cars[i].position[2] = NULL;
			Cars[i].speed += 0.01f;									// increase speed
		}
	}
}

int CGame::getCollision()
{
	return this->crashedCarsCounter;
}

