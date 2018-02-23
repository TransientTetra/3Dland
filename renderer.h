#include "lib.h"
#include "model.h"

#ifndef RENDERER_H
#define RENDERER_H 1
class renderer
{
private:

public:
	void prepare();
	void render(rawModel model);
};
#endif