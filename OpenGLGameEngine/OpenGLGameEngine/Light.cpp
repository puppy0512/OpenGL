#include "Light.h"

Light::Light()
{
	// how much that color of the object on each pixel will show
	colour = glm::vec3(1.0f, 1.0f, 1.0f);

	// nice, bright
	ambientIntensity = 1.0f;
	diffuseIntensity = 0.0f;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity) {
	
	colour = glm::vec3(red, green, blue);
	ambientIntensity = aIntensity;
	diffuseIntensity = dIntensity;
}

Light::~Light()
{
}
