#include "application.h"

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

	glEnable(GL_DEPTH_TEST);

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

void Application::applicationPollEvents(SDL_Event &event,
		float &deltaMoveSideways, float &deltaMoveForward,
		float &deltaMoveVertically,
		float &deltaPitch, float &deltaRotation)
{	
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				if (event.key.repeat == 0)
				{
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							quit = true;
							break;
						case SDLK_w:
							deltaMoveForward = 0.05f;
							break;
						case SDLK_s:
							deltaMoveForward = -0.05f;
							break;
						case SDLK_a:
							deltaMoveSideways = 0.05f;
							break;
						case SDLK_d:
							deltaMoveSideways = -0.05f;
							break;
						case SDLK_SPACE:
							deltaMoveVertically = 0.05f;
							break;
						case SDLK_LCTRL:
							deltaMoveVertically = -0.05f;
							break;
						case SDLK_DOWN:
							deltaPitch = 0.02f;
							break;
						case SDLK_UP:
							if (deltaPitch > -0.5f)
								deltaPitch = -0.02f;
							break;
						case SDLK_LEFT:
							deltaRotation = 0.02f;
							break;
						case SDLK_RIGHT:
							deltaRotation = -0.02f;
							break;
					}
				}
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym)
				{
					case SDLK_w:
					case SDLK_s:
						deltaMoveForward = 0;
						break;
					case SDLK_d:
					case SDLK_a:
						deltaMoveSideways = 0;
						break;
					case SDLK_SPACE:
					case SDLK_LCTRL:
						deltaMoveVertically = 0;
						break;
					case SDLK_UP:
					case SDLK_DOWN:
						deltaPitch = 0;
						break;
					case SDLK_LEFT:
					case SDLK_RIGHT:
						deltaRotation = 0;
						break;
				}
		}
	}
}

void Application::run()
{
	Vertex cube[] = {
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.5f),	glm::vec2(-1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.5f),	glm::vec2(1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f)),

		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, -0.5f),	glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),	glm::vec2(-1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f),	glm::vec2(1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, -0.5f),	glm::vec2(1.0f, 1.0f)),

		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f),	glm::vec2(1.0f, -1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.5f),	glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.5f),	glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),	glm::vec2(-1.0f, 1.0f)),

		Vertex(glm::vec3(0.5f, -0.5f, 0.5f),	glm::vec2(1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, -0.5f),	glm::vec2(-1.0f, 1.0f)),

		Vertex(glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, -0.5f),	glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),	glm::vec2(-1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),	glm::vec2(-1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, 0.5f, 0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec2(1.0f, -1.0f)),

		Vertex(glm::vec3(0.5f, -0.5f, 0.5f),		glm::vec2(1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f),	glm::vec2(1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec2(-1.0f, 1.0f)),
		Vertex(glm::vec3(-0.5f, -0.5f, 0.5f),	glm::vec2(-1.0f, -1.0f)),
		Vertex(glm::vec3(0.5f, -0.5f, 0.5f),		glm::vec2(1.0f, -1.0f))
	};

	SDL_Event event;
	Shader shader("./res/basic");
	Mesh mesh(cube, sizeof(cube) / sizeof(cube[0]));
	Texture texture("./res/dirt.jpg");
	Transform transform;
	Camera camera(glm::vec3(0, 0, -3), 70.0f, (float)getWindowWidth()/(float)getWindowHeight(), 0.01f, 1000.0f);

	float deltaMoveSideways = 0.0f;
	float deltaMoveForward = 0.0f;
	float deltaMoveVertically = 0.0f;
	float deltaPitch = 0.0f;
	float deltaRotation = 0;

	while (!quit)
	{
		clearDisplay(0.0f, 0.0f, 0.0f);

		camera.moveForward(deltaMoveForward);
		camera.moveSideways(deltaMoveSideways);
		camera.moveVertically(deltaMoveVertically);
		camera.pitch(deltaPitch);
		camera.rotateY(deltaRotation);

		shader.bind();
		shader.update(transform, camera);
		texture.bind(0);
		mesh.draw();

		SDL_GL_SwapWindow(m_window);
		applicationPollEvents(event, deltaMoveSideways, deltaMoveForward, deltaMoveVertically, deltaPitch, deltaRotation);

	}
}