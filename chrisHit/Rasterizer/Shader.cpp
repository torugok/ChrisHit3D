
#include "Shader.h"


Shader::Shader(CHenum type,const char *data)
{
	shaderID = glCreateShader(type);
	glShaderSource(shaderID, 1, &data, NULL);
	glCompileShader(shaderID);
}

Shader::~Shader()
{
	glDeleteShader(shaderID);
}


CHuint Shader::getShaderID()
{
	return shaderID;
}

/*
void Shader::compileShader()
{

}
*/