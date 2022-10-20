#include "Queen.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>


void Queen::drawGeometry(float scale, float x, float y, float z)
{
}

void Queen::drawBody(float scale, float x, float y, float z)
{

}

void Queen::drawBase(float scale)
{
	//Draw cylinder

	glColor3f(1, 0, 1);
	glPushMatrix();
	{
		glScalef(scale, scale, scale);
		glTranslatef(0, 7, 17);

		glRotatef(90, 90, 0, 0);

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, 0);
			glVertex3f(1, 3, 0);
			glVertex3f(3, 1, 0);
			glVertex3f(3, -1, 0);
			glVertex3f(1, -3, 0);
			glVertex3f(-1, -3, 0);
			glVertex3f(-3, -1, 0);
			glVertex3f(-3, 1, 0);
			glVertex3f(-1, 3, 0);
		}
		glEnd();

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, 1);
			glVertex3f(1, 3, 1);
			glVertex3f(3, 1, 1);
			glVertex3f(3, -1, 1);
			glVertex3f(1, -3, 1);
			glVertex3f(-1, -3, 1);
			glVertex3f(-3, -1, 1);
			glVertex3f(-3, 1, 1);
			glVertex3f(-1, 3, 1);
		}
		glEnd();

		glBegin(GL_QUAD_STRIP);
		{

			glVertex3f(-1, 3, 0);
			glVertex3f(-1, 3, 1);

			glVertex3f(1, 3, 0);
			glVertex3f(1, 3, 1);

			glVertex3f(3, 1, 0);
			glVertex3f(3, 1, 1);

			glVertex3f(3, -1, 0);
			glVertex3f(3, -1, 1);

			glVertex3f(1, -3, 0);
			glVertex3f(1, -3, 1);

			glVertex3f(-1, -3, 0);
			glVertex3f(-1, -3, 1);

			glVertex3f(-3, -1, 0);
			glVertex3f(-3, -1, 1);

			glVertex3f(-3, 1, 0);
			glVertex3f(-3, 1, 1);

			glVertex3f(-1, 3, 0);
			glVertex3f(-1, 3, 1);
		}
		glEnd();
	}
	glPopMatrix();
}
