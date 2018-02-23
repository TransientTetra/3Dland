#include "lib.h"

#ifndef APPLICATION_H
#define APPLICATION_H 1
class application
{
private:
	GLFWwindow *window;
public:
	application(int windowWidth, int windowHeight, const char *title);
	void processInput();
	void run();
	void end();
};
#endif