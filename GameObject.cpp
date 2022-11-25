#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>




/// rgb
/// xyz

void GameObject::drawOrigin() {

	glBegin(GL_LINES); 
	{
		//draw x-axis
		//glRotatef(45,1, 1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);

		//draw y-axis
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);

		//draw z-axis
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0,0,1);
	
	
	}
	glEnd();

	glPushMatrix();
	{

		glColor3f(1, 0, 0);
		glTranslatef(1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glutSolidCone(0.1, 0.15, 6, 1);
	}
	glPopMatrix();
	
	glPushMatrix();
	{
		glColor3f(0, 1, 0);
		glTranslatef(0, 1, 0);
		glRotatef(-90, 1, 0, 0);
		glutSolidCone(0.1, 0.15, 6, 1);
	}
	glPopMatrix();
	

	glPushMatrix();
	{
		glColor3f(0, 0, 1);
		//glRotatef(45,1,0,0);
		glTranslatef(0,0,1);
		glutSolidCone(0.1, 0.15, 6, 1);
	}
	glPopMatrix();



}

void GameObject::drawGeometry() {
	
	glColor3f(1, 1, 1);
	glutSolidCube(1);
}



void GameObject::drawCube() {

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

		glColor3f(0, 0, 1);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);

		glPopMatrix();
	}
	glEnd();
}

void GameObject::draw() {
	drawGeometry();
	glDisable(GL_DEPTH_TEST);
	//drawOrigin();
	glEnable(GL_DEPTH_TEST);
}