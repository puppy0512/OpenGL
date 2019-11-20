#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
	lastX = 400;
	lastY = 300;
	mouseFirstMoved = true;

	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
}

Window::Window(GLint windowWidth, GLint windowHeight) {
	width = windowWidth;
	height = windowHeight;
	lastX = windowWidth / 2;
	lastY = windowHeight / 2;
	mouseFirstMoved = true;

	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
}

int Window::initialize(){
	//Initialize GLFW

	if (!glfwInit()) {
		printf("GLFW Initialization failed");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Core profile - No Backwards Compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	mainWindow = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
	if (!mainWindow) {
		printf("GLFW window creation failed");
		glfwTerminate();
		return 1;
	}

	// Get Buffer size information
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);


	// Set Context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Create Handle Key
	createCallbacks();
	glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("GLEW Initialization failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	glfwSetWindowUserPointer(mainWindow, this);

}

void Window::createCallbacks() {
	glfwSetKeyCallback(mainWindow, handleKeys);
	glfwSetCursorPosCallback(mainWindow, handleMouse);
	glfwSetScrollCallback(mainWindow, handleScroll);
}

GLfloat Window::getXChange() {
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}
GLfloat Window::getYChange() {
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}

GLfloat Window::getXOffset() {
	GLfloat theOffset = xOffset;
	xOffset = 0.0f;
	return theOffset;
}

GLfloat Window::getYOffset() {
	GLfloat theOffset = yOffset;
	yOffset = 0.0f;
	return theOffset;
}
void Window::handleKeys(GLFWwindow* window, int key, int code, int action, int mode) {
	Window* thewindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	// if escape key is pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS) {
			thewindow->keys[key] = true;
			printf("Pressed %d\n", key);
		}
		else if (action == GLFW_RELEASE) {
			thewindow->keys[key] = false;
			printf("Released %d\n", key);
		}
	}
}

void Window::handleMouse(GLFWwindow* window, double xPos, double yPos) {
	Window* thewindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (thewindow->mouseFirstMoved) {
		thewindow->lastX = xPos;
		thewindow->lastY = yPos;
		thewindow->mouseFirstMoved = false;
	}

	thewindow->xChange = xPos - thewindow->lastX;
	thewindow->yChange = thewindow->lastY - yPos;

	thewindow->lastX = xPos;
	thewindow->lastY = yPos;

	//printf("x: %.6f, y: %.6f\n", thewindow->xChange, thewindow->yChange);
}

void Window::handleScroll(GLFWwindow* window, double xOffset, double yOffset) {
	Window* thewindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	thewindow->xOffset = xOffset;
	thewindow->yOffset = yOffset;
}

Window::~Window()
{
}
