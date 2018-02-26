#ifndef TEXTURE_H
#define TEXTURE_H
#include "header.h"
class Texture
{
private:
	GLuint textureID;
public:
	Texture(const std::string &fileName);
	virtual ~Texture();
	
	void bind(unsigned int unit);
};
#endif