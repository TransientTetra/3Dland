#ifndef APPLICATION_H
#define APPLICATION_H
#include "header.h"
class Application
{
private:
	SDL_Window *m_window;	
	SDL_GLContext m_glContext;
	bool quit;
public:
	Application(int width, int height, const std::string &title);
	~Application();
	
	void run();
	void clearDisplay(float r, float g, float b);
};
#endif