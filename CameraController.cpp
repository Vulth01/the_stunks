//#include "CameraController.h"
//#include "Time.h"
//#include "Input.h"
//#include "GL/freeglut.h"
//#include "GLFW/glfw3.h"
//#include "GLFW/glfw3native.h"
//#include "iostream"
//
//using namespace glm;
//
//static const int WIDTH = 800;
//static const int HEIGHT = 600;
//
//
//CameraController::CameraController() {
//	forward = vec3(0, 0, -1);
//	up = vec3(0, 1, 0);
//	right = normalize(cross(forward,up));
//	position = vec3();
//	lookAt = position*forward;
//
//	updateCamera();
//}
//void CameraController::updateCamera() {
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(
//		position.x, position.y, position.z, 
//		lookAt.x, lookAt.y, lookAt.z, 
//		up.x, up.y, up.z
//	);
//}
//void CameraController::update() {
//	deltaTime = Time::getDeltaTime();
//
//	updatePosition();
//	updateLook();
//	updateResetCamera();
//	updateCamera();
//	updateCursorLocked();
//}
//void CameraController::setLookSensitivity(float sensitivity) {
//	lookSensitivity = sensitivity;
//}
//void CameraController::setMovementSpeed(float speed) {
//	movementSpeed = speed;
//}
//void CameraController::updateLook() {
//	float xOffset = Input::getMouseDeltaX();
//	float yOffset = Input::getMouseDeltaY();
//	
//	if (mouseFirstMovement)
//	{
//		xOffset = 0;
//		yOffset = 0;
//		mouseFirstMovement = false;
//	}
//
//
//	if (xOffset > 0)
//	{
//		yaw += (10 + lookSensitivity * deltaTime);
//	}
//	else if (xOffset < 0)
//	{
//		yaw -= (10 + lookSensitivity * deltaTime);
//	}
//	
//	
//	if (yOffset > 0)
//	{
//		pitch += (5 + lookSensitivity * deltaTime);
//	}
//	else if (yOffset < 0)
//	{
//		pitch -= (5 + lookSensitivity * deltaTime);
//	}
//
//	std::cout << "PITCH : " << pitch << "    ||||    YAW : " << yaw << std::endl << std::endl;
//	
//	//xOffset *= lookSensitivity * deltaTime;
//	//yOffset *= lookSensitivity * deltaTime;
//
//
//	//yaw += xOffset;
//	//pitch += yOffset;
//	pitch = clamp(pitch, -80.0f, 80.0f);
//
//	float radYaw = radians(yaw);
//	float radPitch = radians(pitch);
//
//	forward = normalize(vec3(
//		cos(radYaw) * cos(radPitch),
//			sin(radPitch),
//			sin(radYaw) * cos(radPitch)
//		));
//	right = normalize(cross(forward, up));
//	lookAt = position + forward;
//
//}
//
//void CameraController::updatePosition() {
//	
//	if (Input::getKeyDown('w') || Input::getKeyDown('W'))
//	{
//		position += forward * movementSpeed * deltaTime;
//	}
//	if (Input::getKeyDown('s') || Input::getKeyDown('S'))
//	{
//		position -= forward * movementSpeed * deltaTime;
//	}
//
//	if (Input::getKeyDown('a') || Input::getKeyDown('A'))
//	{
//		position -= right * movementSpeed * deltaTime;
//	}
//	if (Input::getKeyDown('d') || Input::getKeyDown('D'))
//	{
//		position += right * movementSpeed * deltaTime;
//	}
//}
//
//void CameraController::updateCursorLocked() {
//	glutSetCursor(GLUT_CURSOR_NONE);
//	glutWarpPointer(WIDTH/2,HEIGHT/2);
//}
//
//void CameraController::updateResetCamera() {
//
//}
//






static const int WIDTH = 800;
static const int HEIGHT = 600;



#include "CameraController.h"
#include "Time.h"
#include "Input.h"
#include <GL/freeglut.h>
#include <iostream>

using namespace glm;
using namespace std;

CameraController::CameraController()
{
	forward = vec3(0, 0, -1);
	up = vec3(0, 1, 0);
	right = normalize(cross(forward, up));
	position = vec3();
	lookAt = position + forward;

	camPos = 0;
	updateCameraLocked(camPos);

	startPos.x = position.x; cout << "Position X: " << startPos.x << endl;
	startPos.y = position.y; cout << "Position Y: " << startPos.y << endl;
	startPos.z = position.z; cout << "Position Z: " << startPos.z << endl;

	startLookAt.x = lookAt.x;
	startLookAt.y = lookAt.y;
	startLookAt.z = lookAt.z;

	startUp.x = up.x;
	startUp.y = up.y;
	startUp.z = up.z;

	updateCamera();
}

void CameraController::updateCamera()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		position.x, position.y, position.z,
		lookAt.x, lookAt.y, lookAt.z,
		up.x, up.y, up.z
	);
}

void CameraController::update()
{
	if (!camLocked)
	{
		deltaTime = Time::getDeltaTime();

		updatePosition();
		updateLook();
		//updateResetCamera();
		updateCamera();
	}
	else
	{
		updatePosition();
		updateCamera();
	}

}

void CameraController::setLookSensitivity(float sensitivity)
{
	lookSensitivity = sensitivity;
}

void CameraController::setMovementSpeed(float speed)
{
	movementSpeed = speed;
}

void CameraController::updateLook()
{
	//glutWarpPointer(WIDTH / 2, HEIGHT / 2);
	float xOffset = Input::getMouseDeltaX();
	float yOffset = Input::getMouseDeltaY();

	if (mouseFirstMovement)
	{
		xOffset = 0;
		yOffset = 0;
		mouseFirstMovement = false;
	}

	xOffset *= lookSensitivity * deltaTime;
	yOffset *= lookSensitivity * deltaTime;

	yaw += xOffset;
	pitch += yOffset;
	pitch = clamp(pitch, -80.0f, 80.0f);

	float radYaw = radians(yaw);
	float radPitch = radians(pitch);

	forward = normalize(vec3(
		cos(radYaw) * cos(radPitch),
		sin(radPitch),
		sin(radYaw) * cos(radPitch)
	));

	right = normalize(cross(forward, up));
	lookAt = position + forward;
}

void CameraController::updatePosition()
{

	if (Input::getKeyDown('	'))
	{
		if (camLocked)
		{
			camLocked = false;
			updateResetCamera();
			cout << "Camera Unlocked" << endl;
		}
		else
		{
			camLocked = true;
			cout << "Camera Locked" << endl;
		}
	}

	if (!camLocked)
	{
		//forward
		if (Input::getKeyDown('w') || Input::getKeyDown('W'))
		{
			position += forward * movementSpeed * deltaTime;
		}

		//backward
		if (Input::getKeyDown('s') || Input::getKeyDown('S'))
		{
			position -= forward * movementSpeed * deltaTime;
		}

		//left
		if (Input::getKeyDown('a') || Input::getKeyDown('A'))
		{
			position -= right * movementSpeed * deltaTime;
		}

		//right
		if (Input::getKeyDown('d') || Input::getKeyDown('D'))
		{
			position += right * movementSpeed * deltaTime;
		}
	}
	else
	{
		if (Input::getKeyDown('q') || Input::getKeyDown('Q'))
		{
			camPos--;

			if (camPos < 0)
			{
				camPos = 2;
			}

			updateCameraLocked(camPos);
		}
		else if (Input::getKeyDown('e') || Input::getKeyDown('E'))
		{
			camPos++;

			if (camPos > 2)
			{
				camPos = 0;
			}

			updateCameraLocked(camPos);
		}
	}

	if (Input::getKeyDown(27))
	{
		if (fpsCounterShow)
		{
			fpsCounterShow = false;
		}
		else
		{
			fpsCounterShow = true;
		}
	}
}

void CameraController::updateCameraLocked(int camPos)
{
	if (camPos == 0)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(
			0, 10, 10,
			0, 0, 0,
			0, 1, 0
		);

		position.x = 0;
		position.y = 10;
		position.z = 10;

		lookAt.x = 0;
		lookAt.y = 0;
		lookAt.z = 0;

		up.x = 0;
		up.y = 1;
		up.z = 0;

	}
	else if (camPos == 1)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(
			0, 10, 0,
			0, 0, 0,
			0, 1, 1
		);

		position.x = 0;
		position.y = 10;
		position.z = 0;

		lookAt.x = 0;
		lookAt.y = 0;
		lookAt.z = 0;

		up.x = 0;
		up.y = 1;
		up.z = 1;
	}
	else
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(
			0, 50, -30,
			0, 0, 0,
			0, 0, 1
		);

		position.x = 0;
		position.y = 50;
		position.z = -30;

		lookAt.x = 0;
		lookAt.y = 0;
		lookAt.z = 0;

		up.x = 0;
		up.y = 0;
		up.z = 1;
	}
}

void CameraController::updateCursorLocked()
{
	//TODO: implement cursor lock
}

void CameraController::updateResetCamera()
{
	//TODO: reset camera to the original position
	position.x = startPos.x;
	position.y = startPos.y;
	position.z = startPos.z;

	lookAt.x = startLookAt.x;
	lookAt.y = startLookAt.y;
	lookAt.z = startLookAt.z;

	up.x = startUp.x;
	up.y = startUp.y;
	up.z = startUp.z;
}

bool CameraController::getFpsCounterShow()
{
	return fpsCounterShow;
}