#pragma once

#include <map>
#include <string>

#include <glad/glad.h>

#include <shader.h>

// static singleton ResourceManager class taken from learnopengl.com and modified
// may change this later, not a fan of singletons

class ResourceManager {
public:
	// resource storage
	static std::map<std::string, Shader> shaders;

	// loads (and generates) a shader program from file loading vertex and fragment shader source code
	static Shader loadShader(const char* vShaderFile, const char* fShaderFile, std::string name);

	// retrieves a stored shader
	static Shader getShader(std::string name);

	// properly de-allocates all loaded resources
	static void clear();

private:
	// private constructor, that is we do not want any actual resource manager objects
	// its members and functions should be publicly available (static)
	ResourceManager() {}

	// loads and generates a shader from file
	static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile);
};