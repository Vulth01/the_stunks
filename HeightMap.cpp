#include "HeightMap.h"
#include "Texture.h"
#include <iostream>
#include <GL/glut.h>


void HeightMap::DrawMap(int x, int y, float height) {

	//std::cout << "---- " << height << " ----" << std::endl;
	std::cout << "x - " << x << std::endl;
	std::cout << "y - " << y << std::endl;
	std::cout << "height - " << height << std::endl;
	std::cout << "---------------" << std::endl;


	float coords [64];


	glEnable(GL_DEPTH_TEST);

	glBegin(GL_TRIANGLE_STRIP); 
	{
		glPushMatrix();
		glColor3f(1, 0, 1);

		for (int i = 0; i < x; i+=2)
		{
			for (int j = 0; j < y; j+=2)
			{
				for (int k = 0; k < y; k += 2)
				{
					glVertex3f(i, j, height / 255);
					//(j + width * (i + k))

					
					
					//  =   = 
					//	  
					//	=   =




				}
			}
		}
		glPopMatrix();
	}
	glEnd();

	glDisable(GL_DEPTH_TEST);

}