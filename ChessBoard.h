#pragma once
#include "GameObject.h"

class ChessBoard : public GameObject
{
private:
	void drawGeometry() override;
	void drawBoard();
	void drawCube(bool isBlack, int x, int y, float offset);
	float heightOffset;
	bool ChangeColour;
	void ColourChange();
	bool bwColour;
};
