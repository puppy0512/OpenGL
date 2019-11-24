#pragma once

#include <vector>
#include <string>

#include <assimp/importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"
#include "Texture.h"

// used recursion
// model each mesh has a child mesh -> split nodes (traverse nodes)

class Model
{
public:
	Model();
	~Model();

private:
	std::vector<Mesh*> meshList;
	std::vector<Texture*> textureList;
	std::vector<unsigned int> meshToTex;
};

