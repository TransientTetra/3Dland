#include "lib.h"

#include "struct.h"
#include "draw.h"
#include "position.h"
#include "mouse.h"
#include "keyboard.h"

#define ESC 27

//angles x and y of rotation for camera direction
extern float anglex, angley;

//vector representing camera's direction
extern float lx, ly, lz;

//position of the camera
extern float x, z, y;

//key states for movement
extern float delta_angle_x;
extern float delta_angle_y;
extern float delta_move_forward;
extern float delta_move_sideways;
extern int originx, originy;