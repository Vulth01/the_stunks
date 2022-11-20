#pragma once
static class Time
{
private:
	static int prevTime;
	static int time;

public:
	static void update();
	static float getTime();
	static float getDeltaTime();
	static float getFrameRate();
};

