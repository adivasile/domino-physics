#ifndef VERTEX_H
#define VERTEX_H

#include "common.h"

struct Vertex
{
	GLfloat x, y, z;
	GLfloat nx, ny, nz;
	GLfloat r, g, b, a;
	GLfloat padding[7]; // 32-byte aligned
};

#endif
