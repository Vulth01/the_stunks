#pragma once
#include "GameObject.h"
#include "ModelPart.h"
#include <string>
#include <vector>
#include <GL/freeglut.h>
#include "Texture.h"


class Model : public GameObject
{
public:
	Model(std::string path, std::string name);
	~Model();
private:
	void loadModel(std::string path, std::string name);
	void generateGeometry();
	void drawGeometry() override;

	std::vector<ModelPart> parts;
	std::vector<Texture*> textures;

	GLuint id;
};