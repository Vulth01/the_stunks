#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "GameObject.h"
#include "RainbowCube.h"
#include "Pixel.h"
#include "Light.h"
#include "Texture.h"
#include "TexturedCube.h"
#include "ChessBoard.h"
#include "HeightMap.h"
#include "Model.h"
#include "ChessPiece.h"
#include "Input.h"
#include "CameraController.h"
#include "Time.h"


//TinyObjLoader
#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

//STB
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define LEFT_ARROW 75
#define RIGHT_ARROW 77

using namespace std;


static const int WIDTH = 800;
static const int HEIGHT = 600;

//Creating instances of the used classes
GameObject gameObject;
RainbowCube rainbowCube;
Texture* texture;
TexturedCube gObject;
ChessBoard chessBoard;
HeightMap heightMap;
Model* model;
CameraController* cameraController;

Texture* terrainTexture = new Texture("Textures/terrain_texture.png");

ChessPiece chessPiece;

void input(int key, int x, int y);
void init();
void display();
void timer(int);
void updateCamera();
void drawSkybox();
void drawWoodSpikes();
int cameraPos;

Model* model1;
Model* model2;
Model* model3;

Light* light1;
Light* light2;

Light* pointLight;
Light* directionalLight;
Light* spotLight;

int windowId;
bool isPressed = false;

//Initial Calls + Window Setup
int main(int argc, char* argv[]) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GL_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	//Window initialising
	{
		int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
		int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;
		glutInitWindowPosition(windowX, windowY);
		glutInitWindowSize(WIDTH, HEIGHT);
		windowId = glutCreateWindow("The_Stunks_POE");	
	}

	chessBoard.SetRandom(); //Sets the offset for each chess tile

	glutDisplayFunc(display);
	glutSpecialFunc(input);
	glutTimerFunc(0, timer, 0);

	init();
	glutMainLoop();


	delete texture;
	delete pointLight;
	delete directionalLight;
	delete spotLight;
	delete model;
	delete cameraController;
	delete model1;
	delete model2;
	delete model3;
	delete terrainTexture;

	return 0;
}

//Change Initial Camera View + Texture
void init() {
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (double)WIDTH / (double)HEIGHT, 1.0, 1000.0);
	gluLookAt(
		0, 30 / 1, 50 / 1,
		0, 0, 0,
		0, 1, 0
	);

	glutMotionFunc(Input::mousePositionUpdate);
	glutPassiveMotionFunc(Input::mousePositionUpdate);
	glutKeyboardFunc(Input::keyboardUpdate);
	glutKeyboardUpFunc(Input::keyboardUpUpdate);


	//LIGHTING

	glEnable(GL_LIGHTING);
		pointLight = new Light();
		pointLight->init();
		pointLight->setPosition(glm::vec4(-10, 2, 0, 1));
		pointLight->setAmbient(glm::vec4(1.5f, 0, 1.5f, 0.5f));
		pointLight->setSpecular(glm::vec4(0, 0, 0, 0));
		pointLight->setDiffuse(glm::vec4(1.5f, 0, 1.5f, 0.5f));

		directionalLight = new Light();
		directionalLight->init();
		directionalLight->setPosition(glm::vec4(-100, 2, 0, 1));
		directionalLight->setAmbient(glm::vec4(0.5f, 0.5f, 0.5f, 0.5f));
		directionalLight->setSpecular(glm::vec4(0, 0, 0, 0));
		directionalLight->setDiffuse(glm::vec4(0.25f, 0.25f, 0.25f, 0.5f));

		spotLight = new Light();
		spotLight->init(); 
		spotLight->setPosition(glm::vec4(-10, 2, 0, 1));
		spotLight->setAmbient(glm::vec4(0.1f, 0.1f, 0.1f, 0.5f));
		spotLight->setSpecular(glm::vec4(0, 0, 0, 0));
		spotLight->setDiffuse(glm::vec4(0.50f, 0.50f, 0.50f, 0.5f));



	model1 = new Model("Models/", "crystal_cluster");
	model2 = new Model("Models/", "crystal_cluster2");
	model3 = new Model("Models/", "crystal_cluster3");
	cameraController = new CameraController();
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	texture = new Texture("Textures/cloudimage.png");
}

void display() {

	updateCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(1, 0, 1, 0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Input::updateBefore();
	Time::update();
	cameraController->update();


	//Display HeightMap
	{
		glPushMatrix();
		//texture->use();
		terrainTexture->use();
		glTranslatef(0, -10, 0);
		heightMap.DrawMap(255, 100, terrainTexture);
		glPopMatrix();
	}


	//Display Chess Pieces
	{
		glPushMatrix();
		chessPiece.placePieces();
		glPopMatrix();
	}



	//Display ChessBoard
	{
		glPushMatrix();
		glTranslatef(0, 0.5f, 0);
		glRotatef(90, 1, 0, 0);
		chessBoard.draw();
		glPopMatrix();
	}
	glPopMatrix();

	cout << "FPS: " << Time::getFrameRate() << endl;
	Input::updateAfter();


	//Draw wood along the terrain
	drawWoodSpikes();


	//Display Skybox
	{
		drawSkybox();
	}

	glutSwapBuffers();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);		//	Comment this if you want to pause
}

void updateCamera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double eyeX = 0;

	//Check cameraPos
	{
		if (cameraPos > 2) cameraPos = 0;
		if (cameraPos < 0) cameraPos = 2;
		if (cameraPos == 0)
		{
			eyeX = -5;
		}
		if (cameraPos == 2)
		{
			eyeX = 5;
		}
	}

	gluLookAt(
		0, 0, 5,
		eyeX, 0, 0,
		0, 1, 0
	);
}

void input(int key, int x, int y) {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double eyeX = 0;


	//On Press F4 -> Exit
	if (key == (GLUT_KEY_F4)) 
	{ 
		glutDestroyWindow(windowId); 
	}

	//On Press Right Key
	if (key == (GLUT_KEY_RIGHT)) {
		cout << "D" << endl;
		isPressed = true;
		cameraPos--;
	}

	//On Press Left Key
	else if (key == (GLUT_KEY_LEFT)) {
		cout << "A" << endl;
		isPressed = true;
		cameraPos++;
	}

	//Check cameraPos
	{
		if (cameraPos > 2) cameraPos = 0;
		if (cameraPos < 0) cameraPos = 2;
		if (cameraPos == 0)
		{
			eyeX = -5;
		}
		if (cameraPos == 2)
		{
			eyeX = 5;
		}
	}

	gluLookAt(
		0, 0, 5,
		eyeX, 0, 0,
		0, 1, 0
	);
}

void drawWoodSpikes() {

	glPushMatrix();
	{

		glScalef(2, 2, 2);
		glTranslatef(20, -1, -20);

		for (int i = 0; i < 20; i++)
		{

			glTranslatef(-40.0f, 0, 2.0f);

			for (int j = 0; j < 20; j++)
			{

				glTranslatef(2.0f, 0, 0);
				model1->draw();
			}
		}
	}
	glPopMatrix();

	glPushMatrix();
	{
		glScalef(2, 2, 2);
		glTranslatef(20, -1, -20);

		for (int i = 0; i < 20; i++)
		{

			glTranslatef(-40.0f, 0, 2.0f);

			for (int j = 0; j < 20; j++)
			{

				glTranslatef(2.0f, 0, 0);
				model2->draw();
			}
		}
	}
	glPopMatrix();

	glPushMatrix();
	{
		glScalef(2, 2, 2);
		glTranslatef(20, -1, -20);

		for (int i = 0; i < 40; i++)
		{

			glTranslatef(-40.0f, 0, 1.0f);

			for (int j = 0; j < 40; j++)
			{

				glTranslatef(1.0f, 0, 0);
				model3->draw();
			}
		}
	}
	glPopMatrix();
}

void drawSkybox() {

	//Draw skybox top
	{
		glPushMatrix();
		glColor3f(1, 0, 1);
		glTranslatef(1, 100, 1);
		glScalef(100, 1, 100);
		rainbowCube.drawCube();
		glPopMatrix();
	}

	//Draw skybox bottom
	{
		glPushMatrix();
		glColor3f(0, 1, 1);
		glTranslatef(1, -100, 1);
		glScalef(100, 1, 100);
		rainbowCube.drawCube();
		glPopMatrix();
	}

	//Draw skybox left
	{
		glPushMatrix();
		glColor3f(0, 0, 1);
		glTranslatef(100, 1, 1);
		glScalef(1, 100, 100);
		rainbowCube.drawCube();
		glPopMatrix();
	}

	//Draw skybox right
	{
		glPushMatrix();
		glColor3f(0, 0, 1);
		glTranslatef(-100, 1, 1);
		glScalef(1, 100, 100);
		rainbowCube.drawCube();
		glPopMatrix();
	}

	//Draw skybox front
	{
		glPushMatrix();
		glColor3f(0, 0, 1);
		glTranslatef(1, 1, 100);
		glScalef(100, 100, 1);
		rainbowCube.drawCube();
		glPopMatrix();
	}

	//Draw skybox back
	{
		glPushMatrix();
		glColor3f(0,0,1);
		glTranslatef(1, 1, -100);
		glScalef(100, 100, 1);
		rainbowCube.drawCube();
		glPopMatrix();
	}


}