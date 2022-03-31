
#include "player.hpp"
#include "mesh.hpp"

const float PLAYER_POS[3] = { 0.0f, -17.0f, 0.0f };
const float SPEED = 0.5f;
const float WIDTH = 1.5f;


void SPlayer::updateWorldMatrix()
{
    gfx::GetTranslationMatrix(
        this->position[0],
        this->position[1],
        this->position[2],
        this->worldMatrix
    );
}

SPlayer::SPlayer()
{
    this->position[0] = PLAYER_POS[0];
    this->position[1] = PLAYER_POS[1];
    this->position[2] = PLAYER_POS[2];

    this->width = WIDTH;

    this->speed = SPEED;
    this->updateWorldMatrix();
}

void SPlayer::move(EKey key, float leftbarrier, float rightbarrier)
{
    float xnew = this->position[0];
    float halfWidth = width / 2.0f;

    switch (key) 
    {
    case EKey::LEFT:
        xnew -= this->speed;
        if (xnew - halfWidth > leftbarrier)
        {
            this->position[0] = xnew;
            this->updateWorldMatrix();
        }
        break;
    case EKey::RIGHT:
        xnew += this->speed;
        if (xnew + halfWidth < rightbarrier)
        {
            this->position[0] = xnew;
            this->updateWorldMatrix();
        }
    }
}