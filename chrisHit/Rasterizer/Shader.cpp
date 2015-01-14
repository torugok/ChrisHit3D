
#include "Shader.h"


Shader::Shader(CHenum type,const char *data)
{
	shaderID = glCreateShader(type);
	glShaderSource(shaderID, 1, &data, NULL);
	glCompileShader(shaderID);
}

void Shader::deleteShader()
{
	glDeleteShader(shaderID);
}


Shader::~Shader()
{
	deleteShader();
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