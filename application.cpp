#include "header.h"

Application::Application(int width, int height, const std::string &title)
: m_windowWidth(width), m_windowHeight(height)
{	
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	if (m_window == NULL)
	{
		std::cerr << "Failed to create a window" << std::endl;
	}

	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize" << std::endl;
	}

	quit = false;
}

Application::~Application()
{	
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Application::clearDisplay(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Application::run()
{
	SDL_Event event;

	while (!quit)
	{
		clearDisplay(0.0f, 0.0f, 0.0f);


		// shader.bind();
		// shader.update(transform, camera);
		// texture.bind(0);
		// mesh.draw();

		SDL_GL_SwapWindow(m_window);

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							quit = true;
							break;
					}
			}
		}
	}
}