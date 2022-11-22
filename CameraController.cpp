#include "CameraController.h"
#include "Time.h"
#include "Input.h"
#include "GL/freeglut.h"
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "iostream"

using namespace glm;

static const int WIDTH = 800;
static const int HEIGHT = 600;


CameraController::CameraController() {
	forward = vec3(0, 0, -1);
	up = vec3(0, 1, 0);
	right = normalize(cross(forward, up));
	position = vec3();
	lookAt = position * forward;

	updateCamera();
}
void CameraController::updateCamera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		position.x, position.y, position.z,
		lookAt.x, lookAt.y, lookAt.z,
		up.x, up.y, up.z
	);
}
void CameraController::update() {
	deltaTime = Time::getDeltaTime();

	updatePosition();
	updateLook();
	updateResetCamera();
	updateCamera();
	updateCursorLocked();
}
void CameraController::setLookSensitivity(float sensitivity) {
	lookSensitivity = sensitivity;
}
void CameraController::setMovementSpeed(float speed) {
	movementSpeed = speed;
}
void CameraController::updateLook() {
	float xOffset = Input::getMouseDeltaX();
	float yOffset = Input::getMouseDeltaY();

	if (mouseFirstMovement)
	{
		xOffset = 0;
		yOffset = 0;
		mouseFirstMovement = false;
	}


	if (xOffset > 0)
	{
		yaw += (10 + lookSensitivity * deltaTime);
	}
	else if (xOffset < 0)
	{
		yaw -= (10 + lookSensitivity * deltaTime);
	}


	if (yOffset > 0)
	{
		pitch += (5 + lookSensitivity * deltaTime);
	}
	else if (yOffset < 0)
	{
		pitch -= (5 + lookSensitivity * deltaTime);
	}

	std::cout << "PITCH : " << pitch << "    ||||    YAW : " << yaw << std::endl << std::endl;

	//xOffset *= lookSensitivity * deltaTime;
	//yOffset *= lookSensitivity * deltaTime;


	//yaw += xOffset;
	//pitch += yOffset;
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

void CameraController::updatePosition() {

	if (Input::getKeyDown('w') || Input::getKeyDown('W'))
	{
		position += forward * movementSpeed * deltaTime;
	}
	if (Input::getKeyDown('s') || Input::getKeyDown('S'))
	{
		position -= forward * movementSpeed * deltaTime;
	}
	if (Input::getKeyDown('a') || Input::getKeyDown('A'))
	{
		position -= right * movementSpeed * deltaTime;
	}
	if (Input::getKeyDown('d') || Input::getKeyDown('D'))
	{
		position += right * movementSpeed * deltaTime;
	}

}

void CameraController::updateCursorLocked() {
	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(WIDTH / 2, HEIGHT / 2);
}

void CameraController::updateResetCamera() {

}