#pragma once
#include <glm/glm.hpp>

class Light
{
private:
	unsigned int id = 0;
	glm::vec4 position = { 0,0,0,1 };
	glm::vec4 diffuse = { 1.0,1.0,1.0,1.0 };
	glm::vec4 ambient = { 1.0,1.0,1.0,1.0 };
	glm::vec4 specular = { 1.0, 1.0, 1.0, 1.0 };

public:
	static unsigned int currentID;
	Light();
	void init();
	void setPosition(glm::vec4 value);
	void setDiffuse(glm::vec4 value);
	void setAmbient(glm::vec4 value);
	void setSpecular(glm::vec4 value);
	void enable();
	void disable();

};

