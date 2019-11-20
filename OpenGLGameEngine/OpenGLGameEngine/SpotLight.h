#pragma once
#include "PointLight.h"
class SpotLight :
	public PointLight
{
public:
	SpotLight();
	~SpotLight();

private:
	glm::vec3 direction;

	GLfloat edge, procEdge;
};

