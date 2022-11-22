#pragma once
#include "Vertex.h"
#include <vector>


class ModelPart
{
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

};

