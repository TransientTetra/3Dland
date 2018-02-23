#include "header.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char const *argv[])
{
	application game(800, 600, "3Dland");
	game.run();
	return 0;
}