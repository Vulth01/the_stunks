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
	//Display Pawn Piece
	{
		glPushMatrix();
		king.drawBody(0.12, 0, 0, 2);
		pawn.drawBody(0.12, 0, 0, 0);
		//pawn.drawBody(0.12, 0, 7, 17);
		glPopMatrix();
	}
	

	////Display king Piece
	//{
	//	glPushMatrix();
	//	
	//	glPopMatrix();
	//}

	////Display queen Piece
	//{
	//	glPushMatrix();
	//	queen.drawBody(0, 0, 0, 0);
	//	glPopMatrix();
	//}

	////Display bishop Piece
	//{
	//	glPushMatrix();
	//	bishop.drawBody(0, 0, 0, 0);
	//	glPopMatrix();
	//}

	////Display knight Piece
	//{
	//	glPushMatrix();
	//	knight.drawBody(0, 0, 0, 0);
	//	glPopMatrix();
	//}

	////Display rook Piece
	//{
	//	glPushMatrix();
	//	rook.drawBody(0, 0, 0, 0);
	//	glPopMatrix();
	//}



}
