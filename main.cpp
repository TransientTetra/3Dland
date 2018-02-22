#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class application
{
private:
	GLFWwindow *window;
public:
	application(int windowWidth, int windowHeight, const char *title);
	void run();
	void end();
};

application::application(int windowWidth, int windowHeight, const char *title)
{
	//initializing glfw
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //creating window
    window = glfwCreateWindow(windowWidth, windowHeight, title, NULL, NULL);
    if (window == NULL)
    {
    	std::cerr << "Failed to create glfw window" << std::endl;
    	glfwTerminate();
    	exit(1);
    }

    //loading glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
    	std::cerr << "Failed to initialize glad" << std::endl;
    	glfwTerminate();
    	exit(1);
    }

    glViewport(0, 0, windowWidth, windowHeight);
}

void application::run()
{

}

void application::end()
{

}

int main(int argc, char const *argv[])
{
	application game(800, 600, "3Dland");
	game.run();
	game.end();
	return 0;
}