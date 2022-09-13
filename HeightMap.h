#pragma once
#include "Texture.h"

class HeightMap
{
public: 
	float height = 50, width = 50;
	void DrawMap(float maxHeight, float height, Texture* texture);
	void drawCube(bool isBlack, int x, int y, float offset);
};

