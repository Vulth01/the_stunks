#pragma once
#include "GameObject.h"

class ChessBoard : public GameObject
{
public:
	void SetRandom();
	float nrandom[8][8];
private:
	void drawGeometry() override;
	void drawTiles();
	void drawBoard();
	void drawSide();
	void drawBorder();
	void drawCube(int x, int y, float offset);
	float heightOffset;
	bool ChangeColour;
	bool bwColour;
};


