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
#include "Texture.h"




Rook w_rook1;
Knight w_knight1;
Bishop w_bishop1;
Queen w_queen;
King w_king;
Bishop w_bishop2;
Knight w_knight2;
Rook w_rook2;

Pawn w_pawn1;
Pawn w_pawn2;
Pawn w_pawn3;
Pawn w_pawn4;
Pawn w_pawn5;
Pawn w_pawn6;
Pawn w_pawn7;
Pawn w_pawn8;



Rook b_rook1;
Knight b_knight1;
Bishop b_bishop1;
Queen b_queen;
King b_king;
Bishop b_bishop2;
Knight b_knight2;
Rook b_rook2;

Pawn b_pawn1;
Pawn b_pawn2;
Pawn b_pawn3;
Pawn b_pawn4;
Pawn b_pawn5;
Pawn b_pawn6;
Pawn b_pawn7;
Pawn b_pawn8;


Texture* lTexture = new Texture("Textures/grass_block_side.png");
Texture* dTexture = new Texture("Textures/malachite_texture.png");
Texture* bTexture = new Texture("Textures/wood_texture.png");


void ChessPiece::placePieces()
{
	//Display light pieces
	{
		glTranslatef(0, 0.2, 0);
		glColor3f(1,1,1);
		float scale = 0.12;

		lTexture->use();


		//King
		glPushMatrix();
		w_king.drawBody(scale, 0, 0.1, 1);
		glPopMatrix();
		glPushMatrix();		
		w_pawn1.drawBody(scale,0,7,15);
		glPopMatrix();


		//King's Bishop
		glPushMatrix();
		w_bishop1.drawBody(scale, 1, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		w_pawn3.drawBody(scale, 8, 7, 15);
		glPopMatrix();

		//King's Knight
		glPushMatrix();
		w_knight1.drawBody(scale, 2, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		w_pawn5.drawBody(scale, 16, 7, 15);
		glPopMatrix();

		//King's Rook
		glPushMatrix();
		w_rook1.drawBody(scale, 3, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		w_pawn8.drawBody(scale, 24, 7, 15);
		glPopMatrix();



		//Queen
		glPushMatrix();
		w_queen.drawBody(scale, -1, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		w_pawn2.drawBody(scale, -8, 7, 15);
		glPopMatrix();
		
		//Queen's Bishop
		glPushMatrix();
		w_bishop2.drawBody(scale, -2, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		w_pawn4.drawBody(scale, -16,7,15);
		glPopMatrix();

		//Queen's Knight
		glPushMatrix();
		w_knight2.drawBody(scale, -3, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		w_pawn6.drawBody(scale, -24, 7, 15);
		glPopMatrix();		
		
		//Queen's Rook
		glPushMatrix();
		w_rook2.drawBody(scale, -4, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		w_pawn7.drawBody(scale, -32, 7, 15);
		glPopMatrix();

	}

	//Display dark pieces
	{
		glRotatef(180, 0, 180, 0);
		glTranslatef(1, 0.2, 1);
		glColor3f(0, 0.8, 0.8);
		float scale = 0.12;

		bTexture->use();

		//King
		glPushMatrix();
		b_king.drawBody(scale, 0, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn1.drawBody(scale, 0, 7, 15);
		glPopMatrix();


		//King's Bishop
		glPushMatrix();
		b_bishop1.drawBody(scale, 1, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn3.drawBody(scale, 8, 7, 15);
		glPopMatrix();

		//King's Knight
		glPushMatrix();
		b_knight1.drawBody(scale, 2, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn5.drawBody(scale, 16, 7, 15);
		glPopMatrix();

		//King's Rook
		glPushMatrix();
		b_rook2.drawBody(scale, 3, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn8.drawBody(scale, 24, 7, 15);
		glPopMatrix();



		//Queen
		glPushMatrix();
		b_queen.drawBody(scale, -1, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn2.drawBody(scale, -8, 7, 15);
		glPopMatrix();

		//Queen's Bishop
		glPushMatrix();
		b_bishop2.drawBody(scale, -2, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn4.drawBody(scale, -16, 7, 15);
		glPopMatrix();

		//Queen's Knight
		glPushMatrix();
		b_knight2.drawBody(scale, -3, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn6.drawBody(scale, -24, 7, 15);
		glPopMatrix();

		//Queen's Rook
		glPushMatrix();
		b_rook1.drawBody(scale, -4, 0.1, 1);
		glPopMatrix();
		glPushMatrix();
		b_pawn7.drawBody(scale, -32, 7, 15);
		glPopMatrix();

	}


}


void ChessPiece::animatePieces() 
{
	//false = black || true = white
	//king = 0 || queen = 1
	//pawn 1-8



	w_knight1.animatePiece(true,0);
	//Sleep(2000);
	//b_knight1.animatePiece(false, 0);
	//Sleep(2000);
	//w_pawn2.animatePiece(true, 2);
	//Sleep(2000);
	//b_pawn2.animatePiece(false, 2);
	//Sleep(2000);
	//w_pawn4.animatePiece(true, 4);
	//Sleep(2000);


}