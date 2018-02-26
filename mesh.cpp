#include "header.h"

Mesh::Mesh(Vertex *vertices, unsigned int numVertices)
{
	drawCount = numVertices;

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	positions.reserve(numVertices);
	texCoords.reserve(numVertices);

	for (int i = 0; i < numVertices; ++i)
	{
		positions.push_back(*vertices[i].getPosition());
		texCoords.push_back(*vertices[i].getTexCoord());
	}

	glGenBuffers(NUM_BUFFERS, vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID[POSITION_VBO]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vboID[TEX_COORD_VBO]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);


	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vaoID);
}

void Mesh::draw()
{
	glBindVertexArray(vaoID);

	glDrawArrays(GL_TRIANGLES, 0, drawCount);

	glBindVertexArray(0);
}