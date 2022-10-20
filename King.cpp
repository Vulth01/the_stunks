#include "King.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>


void King::drawGeometry() 
{
	
	drawBase();

	drawBody();

}

void King::drawBase() 
{

}

void King::drawBody() 
{



	//King Head




	glBegin(GL_QUAD_STRIP);
	{

	}
	glEnd();



	//Cone
	glBegin(GL_TRIANGLE_STRIP);
	{

	}
	glEnd();

	
}