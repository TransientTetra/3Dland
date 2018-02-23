#include "lib.h"

#ifndef RAW_MODEL_H
#define RAW_MODEL_H 1
class rawModel
{
private:
	int vaoID;
	int vertexCount;
public:
	rawModel(int id, int count);
	int getVaoID();
	int getVertexCount();
};

class modelLoader
{
private:
	int createVAO();
	void storeDataInAttributeList(int attributeNumber, float *data);
	void unbindVAO();
public:
	rawModel loadToVAO(float *positions, int arraySize);
};
#endif