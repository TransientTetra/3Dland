#ifndef APPLICATION_H
#define APPLICATION_H
#include "header.h"
#include "shader.h"
#include "camera.h"
#include "mesh.h"
#include "transform.h"
#include "texture.h"
class Application
{
private:
	unsigned int m_windowWidth;
	unsigned int m_windowHeight;
	SDL_Window *m_window;	
	SDL_GLContext m_glContext;
	bool quit;
public:
	Application(int width, int height, const std::string &title);
	~Application();
	
	void run();
	void clearDisplay(float r, float g, float b);

	unsigned int getWindowWidth(){return m_windowWidth;}
	unsigned int getWindowHeight(){return m_windowHeight;}
	void applicationPollEvents(SDL_Event &event,
		float &deltaMoveSideways, float &deltaMoveForward,
		float &deltaMoveVertically,
		Camera &camera);
};
#endif