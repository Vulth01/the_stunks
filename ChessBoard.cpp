#include "ChessBoard.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>



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
			offset = (rand() % 2) + 1;
			//offset = 0;
			drawCube(colourCheck, x * 2, y * 2, offset);
			colourCheck = !colourCheck;
		}
	}
	for (int x = -4; x < 3; x++)
	{
		for (int y = 4; y < 5; y++)
		{
			offset = (rand() % 2) + 1;
			drawCube(colourCheck, (x * 2), (y * 2) - 2, offset);
			colourCheck = !colourCheck;
		}
	}
	for (int x = 4; x < 5; x++)
	{
		for (int y = -5; y < 3; y++)
		{
			offset = (rand() % 2) + 1;
			colourCheck = !colourCheck;
			drawCube(colourCheck, (x * 2) - 2, (y * 2) + 2, offset);
		}
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