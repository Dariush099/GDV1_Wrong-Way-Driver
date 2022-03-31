
#include "block.hpp"

SBlock::SBlock()
{

}

SBlock::SBlock(float position[3])
{
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->position[2] = position[2];
}