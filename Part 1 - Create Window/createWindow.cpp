#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Global Variables
const char* APP_TITLE = "Window Creation";
const int gWindowWidth = 800;
const int gWindowHeight = 600;

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);

// Main Application Entry Point
int main()
{
	if (!glfwInit())
	{
		std::cerr << "GLFW initialization failed" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* pWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, APP_TITLE, NULL, NULL);
	if (pWindow == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
    // Current Window 
	glfwMakeContextCurrent(pWindow);

    glfwSetKeyCallback(pWindow, glfw_onKey);

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	// Rendering loop
	while (!glfwWindowShouldClose(pWindow))
	{
		glfwPollEvents();

        // Blueish Color
		glClearColor(0.23f, 0.38f, 0.47f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(pWindow);
	}

	// Close
	glfwTerminate();
	return 0;
}

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode) 
{
    // if we hit escape key, close the window
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

