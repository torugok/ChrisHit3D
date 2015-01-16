#define GLEW_STATIC
#include <GL\glew.h>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <glm.hpp>

#define VERTEX_SHADER GL_VERTEX_SHADER
#define FRAGMENT_SHADER GL_FRAGMENT_SHADER
#define COLOR_BUFFER GL_COLOR_BUFFER_BIT
#define DEPTH_BUFFER GL_DEPTH_BUFFER_BIT

typedef GLenum CHenum;
typedef GLuint CHuint;
typedef GLint CHint;
typedef GLfloat CHfloat;
typedef GLvoid CHvoid;
typedef GLsizeiptr CHsizeiptr;
typedef GLsizei CHsizei;