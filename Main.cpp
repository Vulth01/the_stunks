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

#define LEFT_ARROW 75
#define RIGHT_ARROW 77

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

	int c = getch();
	inputKeys(c);

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

	updateCamera();
	gluLookAt(
		0, 30, 50,
		0, 0, 0,
		0, 1, 0
	);

	camera = new CameraController();
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	texture = new Texture("Textures/cloudimage.png");

	
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(1, 0, 1, 0);	

	glPushMatrix();
	glTranslatef(-25,0,-25);
	heightMap.DrawMap(10, 50, texture);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 7, 0);
	glRotatef(90,1,0,0);
	chessBoard.draw();
	glPopMatrix();

	glutSwapBuffers();

}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);
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

/*void inputKeys(unsigned char key, int x, int y) {
	if (key == 'a')	cameraPos--;
	if (key == 'd')	cameraPos++;
	
	if (cameraPos > 2) cameraPos = 0;
	if (cameraPos < 0) cameraPos = 2;

	cout << "cameraPos: " << cameraPos << endl;*/

	void inputKeys(int key) {
	if (key == LEFT_ARROW)	cameraPos--;
	if (key == RIGHT_ARROW)	cameraPos++;
	
	if (cameraPos > 2) cameraPos = 0;
	if (cameraPos < 0) cameraPos = 2;

	cout << "cameraPos: " << cameraPos << endl;
}