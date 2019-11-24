#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
class Camera
{
public:
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);
	void keyControl(bool* keys, GLfloat deltaTime);
	void mouseControl(GLfloat xChange, GLfloat yChange);
	GLfloat scrollControl(GLfloat xOffset, GLfloat yOffset);
	glm::mat4 calculateViewMatrix();

	glm::vec3 getCameraPosition();
	glm::vec3 getCameraDirection();

	~Camera();

private:
	// the position of the camera
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);

	// the direction of the camera
	glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);;
	
	// the up vector of the camera
	glm::vec3 up;

	// the right vector of the camera
	glm::vec3 right;

	// the direction to sky
	glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);;

	// left or right (rotation around Y-axis)
	GLfloat yaw = 0.0f;

	// up or down (rotation around X-axis)
	GLfloat pitch = 0.0f;

	// Default value for field of view is 45 degrees
	GLfloat fov = 45.0f;

	GLfloat moveSpeed = 0.0f;

	// mouse sensitivity
	GLfloat turnSpeed = 0.0f;

	void update();
};

