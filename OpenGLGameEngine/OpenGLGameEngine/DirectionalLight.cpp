#include "DirectionalLight.h"


DirectionalLight::DirectionalLight() : Light()
{
	// arrow pointing straight down
	direction = glm::vec3(0.0f, -1.0f, 0.0f);
}

DirectionalLight::DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, 
								   GLfloat aIntensity, GLfloat dIntensity,
								   GLfloat xDir, GLfloat yDir, GLfloat zDir) : Light(red, green, blue, aIntensity, dIntensity){

	direction = glm::vec3(xDir, yDir, zDir);
}

void DirectionalLight::UseLight(GLfloat aIntensityLocation, GLfloat aColourLocation,
	GLfloat dIntensityLocation, GLfloat directionLocation) {
	// gluniform binds location witht eh value
	glUniform3f(aColourLocation, colour.x, colour.y, colour.z);
	glUniform1f(aIntensityLocation, ambientIntensity);

	glUniform3f(directionLocation, direction.x, direction.y, direction.z);
	glUniform1f(dIntensityLocation, diffuseIntensity);
}

DirectionalLight::~DirectionalLight()
{
}
