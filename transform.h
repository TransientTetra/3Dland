#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "header.h"
class Transform
{
private:
	glm::vec3 m_pos;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
public:
	Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rotation = glm::vec3(), const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f))
	: m_pos(pos), m_rotation(rotation), m_scale(scale)
	{}
	
	glm::mat4 getModel() const
	{
		glm::mat4 posMatrix = glm::translate(m_pos);
		glm::mat4 scaleMatrix = glm::scale(m_scale);

		glm::mat4 xRotationMatrix = glm::rotate(m_rotation.x, glm::vec3(1, 0, 0));
		glm::mat4 yRotationMatrix = glm::rotate(m_rotation.y, glm::vec3(0, 1, 0));
		glm::mat4 zRotationMatrix = glm::rotate(m_rotation.z, glm::vec3(0, 0, 1));

		return posMatrix * zRotationMatrix * yRotationMatrix * xRotationMatrix * scaleMatrix;
	}

	glm::vec3 &getPos(){return m_pos;}
	glm::vec3 &getRotation(){return m_rotation;}
	glm::vec3 &getScale(){return m_scale;}
	
	void setPos(const glm::vec3 &pos){m_pos = pos;}
	void setRotation(const glm::vec3 &rotation){m_rotation = rotation;}
	void setScale(const glm::vec3 &scale){m_scale = scale;}	
};
#endif