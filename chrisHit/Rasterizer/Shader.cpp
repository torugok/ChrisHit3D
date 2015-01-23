
#include "Shader.h"

namespace chrisHit
{
	Shader::Shader(CHenum type, const char *data)
	{
		shaderID = glCreateShader(type);
		glShaderSource(shaderID, 1, &data, NULL);
		glCompileShader(shaderID);
	}

	Shader::~Shader()
	{
		glDeleteShader(shaderID);
	}


	ShaderHandler Shader::getShaderHandle()
	{
		return shaderID;
	}
}
/*
void Shader::compileShader()
{

}
*/