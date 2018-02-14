#include "headers.h"

void mouse_button(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			anglex += delta_angle_x;
			angley += delta_angle_y;
			originx = -1;
			originy = -1;
		}
		else
		{
			originx = x;
			originy = y;
		}
	}
}

void mouse_motion(int x, int y)
{
	if (originx >= 0)
	{
		delta_angle_x = (x - originx) * 0.0015f;

		lx = sin(anglex + delta_angle_x);
		lz = -cos(anglex + delta_angle_x);
	}
	if (originy >= 0)
	{
		delta_angle_y = (y - originy) * 0.0015f;

		ly = sin(angley + delta_angle_y);
	}
}