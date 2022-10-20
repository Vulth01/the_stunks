#include "ChessPiece.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>

#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"



King king;
Queen queen;
Bishop bishop;
Knight knight;
Rook rook;
Pawn pawn;



void ChessPiece::placePieces()
{
	//Display each piece
	{
		glPushMatrix();
		
		king.drawBody(0.12, 0, 0.15, 1);
		
		pawn.drawBody(0.12, 0, 7, 10);
		
		queen.drawBody(1, -8, -7, -10);

		bishop.drawBody(1, -9, 0, 0);
		bishop.drawBody(1, (8 * 3) +1, 0, 0);

		knight.drawBody(1, +8, 0, 0);
		knight.drawBody(1, -8*5, 0, 0);
		
		rook.drawBody(1, -8, 0, 0);
		rook.drawBody(1, 8*7, 2, 0);

		glPopMatrix();
	}
}
