
#ifndef SHADER_H
#define SHADER_H

#include "..\Base\Common.h"

class Shader
{
private:
	CHuint shaderID;
public:
	Shader(CHenum type, const char *data);
	~Shader();

	CHuint getShaderID();
	//void compileShader();
};

#endif