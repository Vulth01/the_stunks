#pragma once
#include "Texture.h"

class HeightMap
{
public: 
	void DrawMap(int x, int y, float height);
	void drawCube(bool isBlack, int x, int y, float offset);

};

