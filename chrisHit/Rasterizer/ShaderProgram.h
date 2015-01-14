#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "..\Base\Common.h"

#include "Shader.h"


class ShaderProgram
{
private:
	CHuint program;
	Shader *vert, *frag;
public:
	ShaderProgram(Shader *_vert, Shader *_frag);
	ShaderProgram();
	void deleteProgram();
	~ShaderProgram();
	//void attachVertShader(Shader *vert);
	//void attachFragShader(Shader *frag);

	void enableProgram();
	void disableProgram();

	CHuint getProgramID();
	CHint getAttribLocation(const char *name);

};

#endif
