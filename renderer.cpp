#include "header.h"

void renderer::prepare()
{
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void renderer::render(rawModel model)
{
	glBindVertexArray(model.getVaoID());
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}