#ifndef CAMERA_H
#define CAMERA_H
#include "header.h"
class Camera
{
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
public:
	Camera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;

		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
	}

	void moveForward()
	{
		m_position.z += 0.1f;
	}
	void moveBack()
	{
		m_position.z -= 0.1f;
	}
	void moveLeft()
	{
		m_position.x += 0.1f;
	}
	void moveRight()
	{
		m_position.x -= 0.1f;
	}


	glm::mat4 getViewProjection() const
	{
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}	
};
#endif