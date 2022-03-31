
#pragma once

#include "yoshix_fix_function.h"
#include "game.hpp"
#include "key.hpp"

using namespace gfx;

class CApplication : public gfx::IApplication
{
	public:
		CApplication();
		virtual ~CApplication();

	private:

        float fieldOfViewY;
		BHandle playerMesh;
		BHandle cubeMesh;
        BHandle blockMesh;
        BHandle lifeIndicatorMesh;
        BHandle playerTexture;
        BHandle cubeTexture;
        BHandle blockTexture;
        BHandle lifeIndicatorTexture;

        // Game
        CGame* game;
        EKey key;
        bool textureIsSetTo2;
        bool textureIsSetTo1;

	private:
        virtual bool InternOnStartup();
        virtual bool InternOnCreateTextures();
        virtual bool InternOnReleaseTextures();
        virtual bool InternOnCreateMeshes();
        virtual bool InternOnReleaseMeshes();
        virtual bool InternOnResize(int width, int height);
        virtual bool InternOnKeyEvent(unsigned int key, bool isDown, bool altDown);
        virtual bool InternOnUpdate();
        virtual bool InternOnFrame();
};
