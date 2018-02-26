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
	float m_verticalAngle;
public:
	Camera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		m_verticalAngle = 0.0f;

		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
	}

	void moveForward(float distance)
	{
		m_position.z += distance * m_forward.z;
		m_position.x += distance * m_forward.x;
	}
	void moveSideways(float distance)
	{
		glm::vec3 right = glm::normalize(glm::cross(m_up, m_forward));
		m_position.x += distance * right.x;
		m_position.z += distance * right.z;
	}
	void moveVertically(float distance)
	{
		m_position.y += distance;
	}

	void pitch(float angle)
	{
		glm::vec3 right = glm::normalize(glm::cross(m_up, m_forward));

		m_forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(m_forward, 0.0)));
		m_up = glm::normalize(glm::cross(m_forward, right));
		m_verticalAngle += angle;
	}

	void rotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		m_forward = glm::vec3(glm::normalize(rotation * glm::vec4(m_forward, 0.0)));
		m_up = glm::vec3(glm::normalize(rotation * glm::vec4(m_up, 0.0)));
	}


	glm::mat4 getViewProjection() const
	{
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}	
};
#endif