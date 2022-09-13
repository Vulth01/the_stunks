#include "ChessBoard.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>


void ChessBoard::SetRandom() {
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			float ran = (rand() % 20 + 1);
			nrandom[x][y] = (ran / 10);

			std::cout << " ====Random Set==== : " << nrandom[x][y] << std::endl;
		}
	}
}


void ChessBoard::ColourChange() {
    bwColour = !bwColour;
}

void ChessBoard::drawGeometry() 
{
	
	// beep boop

	bool colourCheck = false;
	float offset;
	
	for (int x = -4; x < 3; x++)
	{
		for (int y = -4; y < 3; y++)
		{
			offset = nrandom[x+4][y+4];
			//offset = 0;
			drawCube(colourCheck, x * 2, y * 2, offset);
			colourCheck = !colourCheck;
		}
	}
	for (int x = -4; x < 3; x++)
	{
		for (int y = 4; y < 5; y++)
		{
			offset = nrandom[x+4][y+4];
			drawCube(colourCheck, (x * 2), (y * 2) - 2, offset);
			colourCheck = !colourCheck;
		}
	}
	for (int x = 4; x < 5; x++)
	{
		for (int y = -5; y < 3; y++)
		{
			offset = nrandom[x+4][y+4];
			colourCheck = !colourCheck;
			drawCube(colourCheck, (x * 2) - 2, (y * 2) + 2, offset);
		}
	}

	drawBorder();

}

void ChessBoard::drawBorder() {
	glBegin(GL_QUADS);
	{

		//10 - 8       6 - 8
		glColor3f(0.3f, 0.3f, 0.3f);

		GLfloat BorderPos[8][8];

		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				glVertex3f(BorderPos[x][y], BorderPos[x][y], BorderPos[x][y]);
			}
		}

		glVertex3f(-10, -10, 5);
		glVertex3f(-10, -8, 5);
		glVertex3f(-8, -8, 5);
		glVertex3f(-8, -10, 5);

		glVertex3f(6, 6, 6);
		glVertex3f(6, 8, 6);
		glVertex3f(8, 8, 6);
		glVertex3f(8, 6, 6);

		glVertex3f(-10, -10, 5);
		glVertex3f(-10, -8, 5);
		glVertex3f(-8, -8, 5);
		glVertex3f(-8, -10, 5);

		glVertex3f(6, 6, 6);
		glVertex3f(6, 8, 6);
		glVertex3f(8, 8, 6);
		glVertex3f(8, 6, 6);

	}
}


void ChessBoard::drawCube(bool isBlack, int x, int y, float offset) {
	GLfloat verticeA[] = { -1, -1, -1 };
	GLfloat verticeB[] = { 1, -1, -1, };
	GLfloat verticeC[] = { 1, 1, -1 };
	GLfloat verticeD[] = { -1, 1, -1 };
	GLfloat verticeE[] = { -1, -1, 1 };
	GLfloat verticeF[] = { 1, -1, 1, };
	GLfloat verticeG[] = { 1, 1, 1 };
	GLfloat verticeH[] = { -1, 1, 1 };

	offset /= 2; //this is for it to be between 0 and 0.5 instead of 1

	std::cout << " x : " << x << "   y : "  << y << std::endl;

	glBegin(GL_QUADS);
	{
		glPushMatrix();
		int i = 0;
		
		if (isBlack)
			glColor3f(0,0,0);
		else
			glColor3f(1,1,1);


		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeB[i] + x, verticeB[i + 1] + y, verticeB[i + 2] + offset);
		glVertex3f(verticeC[i] + x, verticeC[i + 1] + y, verticeC[i + 2] + offset);
		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);

		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);
		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);

		glVertex3f(verticeB[i] + x, verticeB[i + 1] + y, verticeB[i + 2] + offset);
		glVertex3f(verticeC[i] + x, verticeC[i + 1] + y, verticeC[i + 2] + offset);
		glVertex3f(verticeG[i] + x, verticeG[i + 1] + y, verticeG[i + 2] + offset);
		glVertex3f(verticeF[i] + x, verticeF[i + 1] + y, verticeF[i + 2] + offset);

		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeB[i] + x, verticeB[i + 1] + y, verticeB[i + 2] + offset);
		glVertex3f(verticeF[i] + x, verticeF[i + 1] + y, verticeF[i + 2] + offset);
		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);

		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);
		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);

		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);
		glVertex3f(verticeC[i] + x, verticeC[i + 1] + y, verticeC[i + 2] + offset);
		glVertex3f(verticeG[i] + x, verticeG[i + 1] + y, verticeG[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);

		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);
		glVertex3f(verticeF[i] + x, verticeF[i + 1] + y, verticeF[i + 2] + offset);
		glVertex3f(verticeG[i] + x, verticeG[i + 1] + y, verticeG[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);

		glPopMatrix();
	}
	glEnd();

}

void ChessBoard::drawBoard() {
    drawGeometry();
    glDisable(GL_DEPTH_TEST);
}