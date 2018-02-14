#include "headers.h"

//angles x and y of rotation for camera direction
float anglex = 0.0f, angley = 0.0f;

//vector representing camera's direction
float lx = 0.0f, ly = 0.0f, lz = 1.0f;

//position of the camera
float x = 0.0f, z = 5.0f, y = 5.0f;

//key states for movement
float delta_angle_x = 0.0f;
float delta_angle_y = 0.0f;
float delta_move_forward = 0;
float delta_move_sideways = 0;
int originx = -1, originy = -1;

int main(int argc, char **argv)
{
	//init glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutCreateWindow("3Dland");

	//callbacks
	glutDisplayFunc(render_scene);
	glutReshapeFunc(reshape_scene);
	glutIdleFunc(render_scene);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(press_normal_key);
	glutKeyboardUpFunc(release_normal_key);
	glutSpecialFunc(press_special_key);
	glutSpecialUpFunc(release_special_key);
	glutMouseFunc(mouse_button);
	glutMotionFunc(mouse_motion);

	//init opengl
	glEnable(GL_DEPTH_TEST);

	//main loop
	glutMainLoop();

	return 0;
}