#include "RainbowCube.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>

void RainbowCube::drawGeometry() {
    
	GLfloat vertices[] = 
	{ 
		-1, -1, -1,
		1, -1, -1,
		1, 1, -1,
		-1, 1, -1,
		-1, -1, 1,
		1, -1, 1,
		1, 1, 1,
		-1, 1, 1
	};
	
	GLfloat verticeA[] = {-1, -1, -1};
	GLfloat verticeB[] = {1, -1, -1,};
	GLfloat verticeC[] = {1, 1, -1};
	GLfloat verticeD[] = {-1, 1, -1};
	GLfloat verticeE[] = {-1, -1, 1};
	GLfloat verticeF[] = {1, -1, 1,};
	GLfloat verticeG[] = {1, 1, 1};
	GLfloat verticeH[] = {-1, 1, 1};

	GLfloat colours[] =
	{
		// -1 is now 0
		0, 0, 0,
		255, 0, 0,
		255, 255, 0,
		0, 255, 0, 
		0, 0, 255,
		1, 0, 255,
		255, 255, 255,
		0, 255, 255
	};
	
	
	
	glBegin(GL_QUADS);
	{
		glPushMatrix();
		
		int i = 0;


		glColor3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		
		glColor3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		
		glColor3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		
		glColor3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);

		glColor3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		
		glColor3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		
		glColor3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		
		glColor3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);

		glColor3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		
		glColor3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		
		glColor3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		
		glColor3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);

		glColor3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		
		glColor3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		
		glColor3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		
		glColor3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);

		glColor3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		
		glColor3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		
		glColor3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		
		glColor3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);

		glColor3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		
		glColor3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		
		glColor3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		
		glColor3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);

		glColor3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		
		glColor3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		
		glColor3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		
		glColor3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);

		glPopMatrix();
	}
	glEnd();
}