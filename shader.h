#ifndef SHADER_H
#define SHADER_H
#include "header.h"
#include "camera.h"
#include "transform.h"
class Shader
{
private:
	static const unsigned int NUM_SHADERS = 2;
	enum
	{
		TRANSFORM_UNIFORM,
		NUM_UNIFORMS
	};
	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];

	std::string loadShader(const std::string& fileName);
	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint createShader(const std::string &text, GLenum shaderType);
public:
	Shader(const std::string &fileName);
	virtual ~Shader();
	
	void bind();
	void update(const Transform &transform, const Camera &camera);
};
#endif