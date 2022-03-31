
#pragma once

#include "yoshix_fix_function.h"

using namespace gfx;

static float CarVertices[][3] =
{
    { -1.0f, -2.0f, 0.0f, },
    {  1.0f, -2.0f, 0.0f, },
    {  1.0f,  2.0f, 0.0f, },
    { -1.0f,  2.0f, 0.0f, },
};

static float CarTexCoords[][2] =
{
    { 0.0f, 1.0f, },
    { 1.0f, 1.0f, },
    { 1.0f, 0.0f, },
    { 0.0f, 0.0f, },
};

static int CarIndices[][3] =
{
    { 0, 1, 2, },
    { 0, 2, 3, },
};

static float BlockVertices[][3] =
{
    { -2.0f, -2.0f, 0.0f, },
    {  2.0f, -2.0f, 0.0f, },
    {  2.0f,  2.0f, 0.0f, },
    { -2.0f,  2.0f, 0.0f, },
};

static float BlockTexCoords[][2] =
{
    { 0.0f, 1.0f, },
    { 1.0f, 1.0f, },
    { 1.0f, 0.0f, },
    { 0.0f, 0.0f, },
};

static int BlockIndices[][3] =
{
    { 0, 1, 2, },
    { 0, 2, 3, },
};

static float LifeIndicatorVertices[][3] =
{
    { -8.0f, -4.5f, 0.0f, },
    {  8.0f, -4.5f, 0.0f, },
    {  8.0f,  4.5f, 0.0f, },
    { -8.0f,  4.5f, 0.0f, },
};

static float LifeIndicatorTexCoords[][2] =
{
    { 0.0f, 1.0f, },
    { 1.0f, 1.0f, },
    { 1.0f, 0.0f, },
    { 0.0f, 0.0f, },
};

static int LifeIndicatorIndices[][3] =
{
    { 0, 1, 2, },
    { 0, 2, 3, },
};

BHandle CreateCarMesh(gfx::BHandle& texture);
BHandle CreateBlockMesh(gfx::BHandle& texture);
BHandle CreateLifeIndicatorMesh(gfx::BHandle& texture);


