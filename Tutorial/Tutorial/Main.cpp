#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

//Event Callbacks(Resize, Inputs)
//If We Only Resize The GLFWwindow, We Also Need To Resize The Render Viewport
{
	glViewport(0, 0, width, height);
}

//Input Event On The Current Window Context, Using GLFW Input System
//Sets The While Loop To False, Closing The Window/Program
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main()
{
	//Setup OpenGL/GLFW Context(Initialization, Version Arrangments, Profile)
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMAP, GL_TRUE); - Only Needed On MacOS

	//Create Window(Window Features, Error Handling, Thread Context)
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW windw" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	//Create Glad Context For OpenGL(OS specific, OS compiling)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize Glad" << std::endl;
		return -1;
	}


	//OpenGL Viewport Context(Window Start Location, Resolution)
	//Making The OpenGL Resolution Less Only Changes The Render Viewport
	glViewport(0, 0, 800, 600);

	
	//Tell GLFW We Want To Resize OpenGL
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//While Loop For Keeping The Window Running
	while (!glfwWindowShouldClose(window))
	{
		//Input Event
		processInput(window);

		//Rendering Commands(Clear The Color Buffer And Set Color)
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Checking For Triggered Events, Swap The Color Buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//Clean/Delete Allocated Data
	glfwTerminate();
}