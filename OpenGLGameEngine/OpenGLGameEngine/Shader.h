#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include "DirectionalLight.h"
#include "PointLight.h"
#include "CommonValues.h"

class Shader
{
public:
	Shader();
	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);
	std::string ReadFile(const char* fileLocation);
	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetAmbientIntensityLocation();
	GLuint GetAmbientColourLocation();
	GLuint GetDiffuseIntensityLocation();
	GLuint GetDirectionLocation();
	GLuint GetSpecularIntensityLocation();
	GLuint GetEyePositionLocation();
	GLuint GetShininessLocation();

	void SetDirectionalLight(DirectionalLight* dLight);
	void SetPointLights(PointLight* pLight, unsigned int lightCount);
	void UseShader();
	void ClearShader();


	~Shader();
private:
	int pointLightCount;

	GLuint shaderID, uniformProjection, uniformModel, uniformView, uniformEyePosition,
		uniformSpecularIntensity, uniformShininess, uniformPointLightCount;

	struct {
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformDirection;
	} uniformDirectionalLight;


	struct {
		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntensity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformLinear;
		GLuint uniformExponent;
	} uniformPointLight[MAX_POINT_LIGHTS];

	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

