#ifndef MESH_H
#define MESH_H
#include "header.h"
class Vertex
{
private:
	glm::vec3 m_position;
	glm::vec2 m_texCoord;

public:
	Vertex(const glm::vec3 position, const glm::vec2 texCoord)
	{
		m_position = position;
		m_texCoord = texCoord;
	}
	
	glm::vec3 *getPosition(){return &m_position;}
	glm::vec2 *getTexCoord(){return &m_texCoord;}
};

class Mesh
{
private:
	enum
	{
		POSITION_VBO,
		TEX_COORD_VBO,
		NUM_BUFFERS
	};

	GLuint vaoID;
	GLuint vboID[NUM_BUFFERS];
	unsigned int drawCount;
public:
	Mesh(Vertex *vertices, unsigned int numVertices);
	~Mesh();
	
	void draw();
};
#endif