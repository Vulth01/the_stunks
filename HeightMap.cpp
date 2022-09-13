#include "HeightMap.h"
#include "Texture.h"
#include <iostream>
#include <GL/glut.h>
#include <random>


void HeightMap::DrawMap(float maxHeight, float size) {

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x  < width - 1; x ++)
		{
			Pixel p1 = getPixelAt(x,y);
			Pixel p2 = getPixelAt(x, y + 1);
			Pixel p3 = getPixelAt(x + 1, y);
			Pixel p4 = getPixelAt(x + 1, y + 1);


			float vx1 = (float)x / (float)width * size;
			float vz1 = (float)y + 1 / (float)height * size;
			float vy1 = p1.r * maxHeight;

			float vx2 = (float)x / (float)width * size;
			float vz2 = (float)y + 1 / (float)height * size;
			float vy2 = p2.r * maxHeight;

			float vx3 = (float)x / (float)width * size;
			float vz3 = (float)y + 1 / (float)height * size;
			float vy3 = p3.r * maxHeight;

			float vx4 = (float)x / (float)width * size;
			float vz4 = (float)y + 1 / (float)height * size;
			float vy4 = p4.r * maxHeight;


			glBegin(GL_TRIANGLE_STRIP);
			{
				glColor3f(p1.r, p1.r, p1.r);
				glVertex3f(vx1, vy1, vz1);

				glColor3f(p2.r, p2.r, p2.r);
				glVertex3f(vx2, vy2, vz2);

				glColor3f(p3.r, p3.r, p3.r);
				glVertex3f(vx3, vy3, vz3);

				glColor3f(p4.r, p4.r, p4.r);
				glVertex3f(vx4, vy4, vz4);
			}
			glEnd();
		}
	}

	////std::cout << "---- " << height << " ----" << std::endl;
	//std::cout << "x - " << x << std::endl;
	//std::cout << "y - " << y << std::endl;
	//std::cout << "height - " << height << std::endl;
	//std::cout << "---------------" << std::endl;


	//float coords [64];
	////float offset = (rand() % 2) + 1;
	//float offset = _RANDOM_(0.1f,0.9f);
	//float peepee = (rand() % 100) + 1;
	//glEnable(GL_DEPTH_TEST);
	//bool oops = false;
	//
	////>> > random.uniform(1.5, 1.9)
	//	//1.8733202628557872

	//glBegin(GL_POINTS); 
	//{
	//	glPushMatrix();
	//	glColor3f(1, 0, 1);

	//	for (int i = 0; i < x; i+=2)
	//	{
	//		for (int j = 0; j < y; j+=2)
	//		{
	//			drawCube(oops, i, j, peepee/50);
	//			//height / 30
	//			for (int k = 0; k < y; k += 2)
	//			{
	//				glVertex3f(i, j, height / 255);
	//				//(j + width * (i + k))
	//			}
	//			oops = !oops;
	//		}
	//	}
	//	glPopMatrix();
	//}
	//glEnd();

	//glDisable(GL_DEPTH_TEST);

}


Pixel HeightMap::getPixelAt(int x, int y) {
	


}




void HeightMap::drawCube(bool isBlack, int x, int y, float offset) {
	GLfloat verticeA[] = { -1, -1, -1 };
	GLfloat verticeB[] = { 1, -1, -1, };
	GLfloat verticeC[] = { 1, 1, -1 };
	GLfloat verticeD[] = { -1, 1, -1 };
	GLfloat verticeE[] = { -1, -1, 1 };
	GLfloat verticeF[] = { 1, -1, 1, };
	GLfloat verticeG[] = { 1, 1, 1 };
	GLfloat verticeH[] = { -1, 1, 1 };


	GLfloat vertices[50][50];


	glBegin(GL_POINTS);
	{
		glPushMatrix();
		int i = 0;

		if (isBlack)
			glColor3f(0.5f, 0.2f, 1);
		else
			glColor3f(1, 0.4f, 1);

		
		for (int x = 0; x < 50; x++)
		{
			for (int y = 0; y < 50; y++)
			{
				glVertex3f(vertices[x][y], 0, 0);
			}
		}


		//glVertex3f(vertices[0][0] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(x, y, offset);
		//glVertex3f(x,  y, offset);
		//glVertex3f( x,  y, offset);
		//glVertex3f( x,  y, offset);


		glPopMatrix();
	}
	glEnd();

}
