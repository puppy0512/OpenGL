#pragma once
#include <GL/glew.h>
class Mesh
{
public:
	Mesh();

	// passing pointers because they are all arrays
	void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void RenderMesh();
	void ClearMesh();
	~Mesh();
private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;

};

