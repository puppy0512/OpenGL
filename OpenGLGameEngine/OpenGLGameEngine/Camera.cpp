#include "Camera.h"

Camera::Camera() {
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

	yaw = 0.0f;
	pitch = 0.0f;
	moveSpeed = 0.0f;
	turnSpeed = 0.0f;
	update();
}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;
	update();
}

void Camera::keyControl(bool* keys, GLfloat deltaTime) {

	GLfloat velocity = moveSpeed * deltaTime;
	//goes inside
	// moving world to the camera
	if (keys[GLFW_KEY_W]) {
		position += front * velocity;
	}

	// goes towards outside
	// moving world away from the camera
	if (keys[GLFW_KEY_S]) {
		position -= front * velocity;
	}

	if (keys[GLFW_KEY_A]) {
		position -= right * velocity;
	}

	if (keys[GLFW_KEY_D]) {
		position += right * velocity;
	}
}

glm::mat4 Camera::calculateViewMatrix() {

	// position of the camera, target position, and up vector
	// as the camera moves, what camera points has to change ( position + front )
	return glm::lookAt(position, position + front, up);
}

glm::vec3 Camera::getCameraPosition() {
	return position;
}

void Camera::update() {

	// front.x and front.z belongs to the same plane (ground level)
	// cosine function gets the ground component of pitch to calculate for x and z

	// cos(theta) * sin(phi)
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	
	// sin(phi)
	front.y = sin(glm::radians(pitch));
	
	// sin(theta) * sin(phi)
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	//remove the magnitude 
	front = glm::normalize(front);

	// Find the orthonormal vector between front and worldup
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}

void Camera::mouseControl(GLfloat xChange, GLfloat yChange) {
	xChange *= turnSpeed;
	yChange *= turnSpeed;

	yaw += xChange;
	pitch += yChange;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}

	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	update();
}

GLfloat Camera::scrollControl(GLfloat xOffset, GLfloat yOffset) {
	if (fov >= 1.0f && fov <= 45.0f) {
		fov -= yOffset;
	}
	if (fov <= 1.0f) {
		fov = 1.0f;
	}
	if (fov >= 45.0f) {
		fov = 45.0f;
	}
	return fov;
}



Camera::~Camera()
{
}
