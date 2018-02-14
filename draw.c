#include "headers.h"

void reshape_scene(int w, int h)
{
	if (h == 0) h = 1;
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void draw_cube()
{
	//front
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	//back
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	//left
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	//right
	glColor3f(0.5f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();

	//top
	glColor3f(0.0f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	//bottom
	glColor3f(0.5f, 0.0f, 0.5f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
	glEnd();
}

void draw_ground(float red, float green, float blue)
{
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
}

void render_scene()
{
	if (delta_move_forward || delta_move_sideways)
		compute_position(delta_move_forward, delta_move_sideways);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(x, y, z,
			x + lx, y - ly, z + lz,
			0.0f, 1.0f, 0.0f);

	draw_ground(0.9f, 0.9f, 0.9f);

	int l = 5;
	for (int k = 0; k < 5; ++k)
	{
	    for (int i = 0; i < l; ++i)
	    {
	    	for (int j = 0; j < l; ++j)
	    	{
			    glPushMatrix();
			    glTranslatef(i, k, j - 5);
				draw_cube();
			    glPopMatrix();    			
	    	}
	    }
	    --l;
	}


	glutSwapBuffers();
}