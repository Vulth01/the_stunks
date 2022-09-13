#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "GameObject.h"
#include "RainbowCube.h"
#include "Pixel.h"
#include "Texture.h"
#include "TexturedCube.h"
#include "ChessBoard.h"
#include "HeightMap.h"


//STB
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace std;


static const int WIDTH = 800;
static const int HEIGHT = 600;

GameObject gameObject;
RainbowCube rainbowCube;
Texture* texture;
TexturedCube gObject;
ChessBoard chessBoard;
HeightMap heightMap;

void init();
void display();
void timer(int);
void updateCamera();
void inputKeys(unsigned char key, int x, int y);
int cameraPos;

int main(int argc, char* argv[]) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GL_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
	int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2; 
	
	glutInitWindowPosition(windowX, windowY);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("My First Window");
	chessBoard.SetRandom();

	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	//glutKeyboardFunc(inputKeys);
	init();
	glutMainLoop();
	
	delete texture;

	return 0;
}

void init() {

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0, WIDTH, HEIGHT, 0,0,1);
	gluPerspective(50.0, (double)WIDTH / (double)HEIGHT, 1.0, 1000.0);

	//updateCamera();
	gluLookAt(
		0, 0, 40,
		0, 0, 0,
		0, -1, 0
	);

	//camera = new CameraController();
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	texture = new Texture("Textures/cloud.png");

	
}




void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(3, 10, 10, 0);	
	
	for (int x = 0; x <= 8; x++)
	{
		for (int y = 0; y <= 8; y++)
		{
			Pixel p = texture->getPixelAt(x, y);
			//cout << p.r << ", " << p.g << ", " << p.b << ", " << p.a << endl;
			/*cout << "x - " << x << endl;
			cout << "y - " << y << endl;
			cout << "height - " << p.r << endl;*/
			heightMap.DrawMap(x, y, (float)p.r);
			//terrainQuads.SetCoords(x,y,(float)p.r);
		}
	}
	//chessBoard.draw();

	glutSwapBuffers();

}

void timer(int) {
	glutPostRedisplay();
	//glutTimerFunc(1000/60, timer, 0);
}


void updateCamera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	double eyeX = 0;
	if (cameraPos == 0)
	{
		eyeX = -5; 
	}
	if (cameraPos == 2)
	{
		eyeX = 5;
	}

	gluLookAt(
		0, 0, 8,
		eyeX,0,0,
		0, 1, 0
	);
}

void inputKeys(unsigned char key, int x, int y) {
	if (key == 'a')	cameraPos--;
	if (key == 'd')	cameraPos++;
	
	if (cameraPos > 2) cameraPos = 0;
	if (cameraPos < 0) cameraPos = 2;

	cout << "cameraPos: " << cameraPos << endl;
}