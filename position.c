#include "headers.h"

void compute_position(float delta_move_forward, float delta_move_sideways)
{
	x += delta_move_forward * lx * 0.1f;
	z += delta_move_forward * lz * 0.1f;
	x += delta_move_sideways * lz * 0.1f;
	z += delta_move_sideways * -lx * 0.1f;
}