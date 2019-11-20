#pragma once

#include <GL/glew.h>
class Material
{
public:
	Material();
	Material(GLfloat sIntensity, GLfloat shine);
	void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);
	~Material();

private:
	// how much of the light source the object will absorb = reflectiveness of the object
	GLfloat specularIntensity;
	// small -> (spread out of specular light) (high -> all the lights will collect to a small point)
	GLfloat shininess;
};

