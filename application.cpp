#include "header.h"


void resizeWindow(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

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
    glfwMakeContextCurrent(window);

    //loading glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
    	std::cerr << "Failed to initialize glad" << std::endl;
    	glfwTerminate();
    	exit(1);
    }

    glViewport(0, 0, windowWidth, windowHeight);
    glfwSetFramebufferSizeCallback(window, resizeWindow); 
}

void application::processInput()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void application::run()
{
    modelLoader loader;
    renderer rendererOne;

    float vertices[] = {
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,

        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };
    int verticesSize = (sizeof(vertices)) / (sizeof(vertices[0]));

    rawModel model = loader.loadToVAO(vertices, verticesSize);

    while (!glfwWindowShouldClose(window))
    {
        processInput();

        rendererOne.prepare();

        rendererOne.render(model);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    end();
}

void application::end()
{
    glfwTerminate();
}