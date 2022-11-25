#include "HeightMap.h"
#include "Texture.h"
#include <iostream>
#include <GL/glut.h>
#include <random>
#include "Texture.h"


void HeightMap::DrawMap(float maxHeight, float size, Texture* texture) {

	glPushMatrix();
	glTranslatef(-size / 2.0, 0, -size / 2.0);

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{

			Pixel p0 = texture->getPixelAt(1, 1); 
			Pixel p1 = texture->getPixelAt(x, y); 
			Pixel p2 = texture->getPixelAt(x, y + 1); 
			Pixel p3 = texture->getPixelAt(x + 1, y);
			Pixel p4 = texture->getPixelAt(x + 1, y + 1);

			float vy1 = p1.r * maxHeight;
			float vx1 = (float)x / (float)width * size;
			float vz1 = (float)y / (float)height * size;

			float vy2 = p2.r * maxHeight;
			float vx2 = (float)x / (float)width * size;
			float vz2 = (float)(y + 1) / (float)height * size;

			float vy3 = p3.r * maxHeight;
			float vx3 = (float)(x + 1) / (float)width * size;
			float vz3 = (float)y / (float)height * size;

			float vy4 = p4.r * maxHeight;
			float vx4 = (float)(x + 1) / (float)width * size;
			float vz4 = (float)(y + 1) / (float)height * size;


			//Draws each of the calculated points in triangle strip format to form the terrain, based off of the pixel heights 
			//The height is represented by their r value, which is equal to the g and b values, as is any grayscale 'colour/shade'. 
			//For example, (5,5,5) and (123,123,123) are both grey, but different shades. 

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

	glPopMatrix();
}




//void HeightMap::DrawMap(float maxHeight, float size, Texture* texture) {
//	
//	//void GenerateTerrain::renderHeightmap(float size, float h){
//	
//	
//	//Added glGenList to make terrain easier to draw
//	id = glGenLists(1);
//
//	glNewList(id, GL_COMPILE);
//	{
//		//Looping through each pixel in the image and changing its height based off of pixel's r g b values
//		for (int y = 0; y < height - 1; y++)
//		{
//			for (int x = 0; x < width - 1; x++)
//			{
//				Pixel p1 = GenerateTerrain::getPixelAt(x, y);
//				Pixel p2 = GenerateTerrain::getPixelAt(x + 1, y);
//				Pixel p3 = GenerateTerrain::getPixelAt(x, y + 1);
//				Pixel p4 = GenerateTerrain::getPixelAt(x + 1, y + 1);
//
//				double vX1 = ((float)x / width) * size;
//				double vZ1 = ((float)y / height) * size;
//				double vX2 = (((float)x + 1) / width) * size;
//				double vZ2 = (((float)y + 1) / height) * size;
//
//				glBegin(GL_TRIANGLE_STRIP);
//				{
//					glTexCoord2f(0, 0);
//					glColor3f(p1.r, p1.g, p1.b);
//					glVertex3f(vX1, (p1.r) * h, vZ1);
//
//					glTexCoord2f(0, 1);
//					glColor3f(p2.r, p2.g, p2.b);
//					glVertex3f(vX2, (p2.r) * h, vZ1);
//
//					glTexCoord2f(1, 0);
//					glColor3f(p3.r, p3.g, p3.b);
//					glVertex3f(vX1, (p3.r) * h, vZ2);
//
//					glTexCoord2f(1, 1);
//					glColor3f(p4.r, p4.g, p4.b);
//					glVertex3f(vX2, (p4.r) * h, vZ2);
//				}
//				glEnd();
//
//			}
//		}
//	}
//	glDisable(GL_TEXTURE_2D);
//	glEndList();
//}
//
//void GenerateTerrain::drawTerrain(float size)
//{
//	//Centering the terrain (Middle of terrain is at (0, 0, 0))
//	glPushMatrix();
//	glTranslatef(-size / 2.0, 0, -size / 2.0);
//
//	//Using terrain grass texture
//	grassTexture->use();
//
//	glCallList(id);
//
//	glDisable(GL_TEXTURE_2D);
//
//	glPopMatrix();
//}