#include "mesh.hpp"

#include "yoshix_fix_function.h"

static float normals[][3] =
{
    { 0.0f, 0.0f, -1.0f, },             // Normal of vertex 0.
    { 0.0f, 0.0f, -1.0f, },             // Normal of vertex 1.
    { 0.0f, 0.0f, -1.0f, },             // Normal of vertex 2.
    { 0.0f, 0.0f, -1.0f, },             // Normal of vertex 3.
};

BHandle CreateMesh(float* verticies, float* texCoords, int* indicies, BHandle& texture)
{
    SMeshInfo meshInfo;

    meshInfo.m_pVertices = verticies;
    meshInfo.m_pNormals = &normals[0][0];                      // No normals.
    meshInfo.m_pColors = nullptr;                      // No colors.
    meshInfo.m_pTexCoords = texCoords;
    meshInfo.m_NumberOfVertices = 4;
    meshInfo.m_NumberOfIndices = 6;
    meshInfo.m_pIndices = indicies;
    meshInfo.m_pTexture = texture;


    gfx::BHandle mesh = nullptr;
    CreateMesh(meshInfo, &mesh);
    return mesh;
}

BHandle CreateCarMesh(gfx::BHandle& texture)
{
    gfx::BHandle mesh = CreateMesh(&CarVertices[0][0], &CarTexCoords[0][0], &CarIndices[0][0], texture);
    return mesh;
}

BHandle CreateBlockMesh(gfx::BHandle& texture)
{
    gfx::BHandle mesh = CreateMesh(&BlockVertices[0][0], &BlockTexCoords[0][0], &BlockIndices[0][0], texture);
    return mesh;
}

BHandle CreateLifeIndicatorMesh(gfx::BHandle& texture)
{
    gfx::BHandle mesh = CreateMesh(&LifeIndicatorVertices[0][0], &LifeIndicatorTexCoords[0][0], &LifeIndicatorIndices[0][0], texture);
    return mesh;
}