#include "headers.h"

void press_normal_key(unsigned char key, int xx, int yy)
{
	switch (key)
	{
		case ESC:
			exit(0);
			break;
		case 'w':
			delta_move_forward = 0.8f;
			break;
		case 's':
			delta_move_forward = -0.8f;
			break;
		case 'a':
			delta_move_sideways = 0.8f;
			break;
		case 'd':
			delta_move_sideways = -0.8f;
			break;
	}
}

void release_normal_key(unsigned char key, int xx, int yy)
{
	switch (key)
	{
		case 'w':
		case 's':
			delta_move_forward = 0;
			break;
		case 'a':
		case 'd':
			delta_move_sideways = 0;
			break;
	}
}

void press_special_key(int key, int xx, int yy)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			delta_move_forward = 0.8f;
			break;
		case GLUT_KEY_DOWN:
			delta_move_forward = -0.8f;
			break;
		case GLUT_KEY_RIGHT:
			delta_move_sideways = -0.8f;
			break;
		case GLUT_KEY_LEFT:
			delta_move_sideways = 0.8f;
			break;
	}
}

void release_special_key(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN:
			delta_move_forward = 0;
			break;
		case GLUT_KEY_RIGHT:
		case GLUT_KEY_LEFT:
			delta_move_sideways = 0;
			break;
	}
}