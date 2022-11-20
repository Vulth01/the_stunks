#include "Time.h"
#include <GL/freeglut.h>

int Time::prevTime = 0;
int Time::time = 0;

void Time::update() {

	prevTime = time;
	time = glutGet(GLUT_ELAPSED_TIME);
}


float Time::getTime() {
	return time / 1000.0f;
}
float Time::getDeltaTime() {
	return (time - prevTime) / 1000.0f;
}
float Time::getFrameRate() {
	return 1.0f / getDeltaTime();
}