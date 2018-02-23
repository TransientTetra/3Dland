#include "header.h"

rawModel::rawModel(int id, int count) : vaoID(id), vertexCount(count){}

int rawModel::getVaoID()
{
	return vaoID;
}

int rawModel::getVertexCount()
{
	return vertexCount;
}

///////////////////////////////////////////////////////////////////////////////

int modelLoader::createVAO()
{
	unsigned int vaoID = 0;
	glGenVertexArrays(1, &vaoID);
	if (vaoID == 0)
	{
		std::cerr << "Couldn't create a VAO" << std::endl;
	}
	glBindVertexArray(vaoID);
	return vaoID;
}

void modelLoader::storeDataInAttributeList(int attributeNumber, float *positions)
{
	unsigned int vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void modelLoader::unbindVAO()
{
	glBindVertexArray(0);
}

rawModel modelLoader::loadToVAO(float *positions, int arraySize)
{
	int vaoID = createVAO();
	storeDataInAttributeList(0, positions);
	unbindVAO();
	return rawModel(vaoID, arraySize / 3);
}