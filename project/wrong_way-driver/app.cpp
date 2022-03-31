
#include "app.hpp"
#include "mesh.hpp"
#include "data.hpp"
#include "light.hpp"

#include "yoshix_fix_function.h"


CApplication::CApplication()
    : fieldOfViewY(90.0f)
    , cubeMesh(nullptr)
    , cubeTexture(nullptr)
    , playerMesh(nullptr)
    , playerTexture(nullptr)
    , blockMesh(nullptr)
    , blockTexture(nullptr)
    , game(nullptr)
    , key(EKey::NONE)
    , textureIsSetTo2(false)
    , textureIsSetTo1(false)
    , lifeIndicatorMesh(nullptr)
    , lifeIndicatorTexture(nullptr)
{

}

CApplication::~CApplication()
{
	
}

bool CApplication::InternOnStartup() {
    this->game = new CGame();
    return true;
}

bool CApplication::InternOnCreateTextures()
{
	CreateTexture("..\\..\\..\\data\\car_red.png", &cubeTexture);
	CreateTexture("..\\..\\..\\data\\car_blue.png", &playerTexture);
	CreateTexture("..\\..\\..\\data\\background_trees.png", &blockTexture);
	CreateTexture("..\\..\\..\\data\\lives_3.png", &lifeIndicatorTexture);

	return true;
}

bool CApplication::InternOnReleaseTextures()
{
	ReleaseTexture(cubeTexture);
	ReleaseTexture(playerTexture);
	ReleaseTexture(blockTexture);
	ReleaseTexture(lifeIndicatorTexture);

    return true;
}

bool CApplication::InternOnCreateMeshes()
{
    this->cubeMesh = CreateCarMesh(this->cubeTexture);
    this->playerMesh = CreateCarMesh(this->playerTexture);
    this->blockMesh = CreateBlockMesh(this->blockTexture);
    this->lifeIndicatorMesh = CreateLifeIndicatorMesh(this->lifeIndicatorTexture);

    return true;
}

bool CApplication::InternOnReleaseMeshes()
{
    ReleaseMesh(this->cubeMesh);
    ReleaseMesh(this->playerMesh);
    ReleaseMesh(this->blockMesh);
    ReleaseMesh(this->lifeIndicatorMesh);

    return true;
}

bool CApplication::InternOnResize(int width, int height)
{
    SLight light;
    float ProjectionMatrix[16];

    GetProjectionMatrix(this->fieldOfViewY, static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f, ProjectionMatrix);

    SetProjectionMatrix(ProjectionMatrix);

    SetLightPosition(light.position);
    SetLightColor(light.ambient, light.diffuse, light.specular, 127);

    return true;
}

bool CApplication::InternOnKeyEvent(unsigned int key, bool isDown, bool altDown)
{
    switch (key)
    {
    case KEY_LEFT:
        this->key = EKey::LEFT;
        break;

    case KEY_RIGHT:
        this->key = EKey::RIGHT;
        break;

    default:
        this->key = EKey::NONE;
    }

    if (!isDown) {
        this->key = EKey::NONE;
    }

    return true;
}

bool CApplication::InternOnUpdate()
{
    float Eye[3];
    float At[3];
    float Up[3];

    float WorldMatrix[16];

    float ViewMatrix[16];

    Eye[0] = 0.0f; At[0] = 0.0f; Up[0] = 0.0f;
    Eye[1] = 0.0f; At[1] = 0.0f; Up[1] = 1.0f;
    Eye[2] = -20.0f; At[2] = 0.0f; Up[2] = 0.0f;

    GetViewMatrix(Eye, At, Up, ViewMatrix);

    SetViewMatrix(ViewMatrix);

    this->game->onUpdate(this->key);


    // set new Texture if the player crashes
    if (this->game->getCollision() == 1 && this->textureIsSetTo2 == false)
    {
        ReleaseTexture(lifeIndicatorTexture);
        ReleaseMesh(this->lifeIndicatorMesh);
        CreateTexture("..\\..\\..\\data\\lives_2.png", &lifeIndicatorTexture);
        this->lifeIndicatorMesh = CreateLifeIndicatorMesh(this->lifeIndicatorTexture);
        textureIsSetTo2 = true;
    }
    else if (this->game->getCollision() == 2 && this->textureIsSetTo1 == false)
    {
        ReleaseTexture(lifeIndicatorTexture);
        ReleaseMesh(this->lifeIndicatorMesh);
        CreateTexture("..\\..\\..\\data\\lives_1.png", &lifeIndicatorTexture);
        this->lifeIndicatorMesh = CreateLifeIndicatorMesh(this->lifeIndicatorTexture);
        textureIsSetTo1 = true;
    }
    else if (this->game->getCollision() == 3)
    {
        // app stops if the player crashed 3 times
        StopApplication();
    }



    return true;
}

bool CApplication::InternOnFrame()
{
    float WorldMatrix[16];

    
    SPlayer player = this->game->getPlayer();
  
    for (int i = 0; i < NUMBER_OF_BLOCKS; i++)
    {
        GetTranslationMatrix(this->game->getBlock(i).position[0], this->game->getBlock(i).position[1], this->game->getBlock(i).position[2], WorldMatrix);
        SetWorldMatrix(WorldMatrix);
        DrawMesh(this->blockMesh);
    }

    for (int i = 0; i < NUMBER_OF_CARS; i++)
    {
        GetTranslationMatrix(this->game->getCar(i).position[0], this->game->getCar(i).position[1], this->game->getCar(i).position[2], WorldMatrix);
        SetWorldMatrix(WorldMatrix);
        DrawMesh(this->cubeMesh);
    }
    
    GetTranslationMatrix(player.position[0], player.position[1], player.position[2], WorldMatrix);

    SetWorldMatrix(WorldMatrix);

    DrawMesh(this->playerMesh);
    
    GetTranslationMatrix(30.0f, 15.0f, 0.0f, WorldMatrix);

    SetWorldMatrix(WorldMatrix);

    DrawMesh(this->lifeIndicatorMesh);

    return true;
}
