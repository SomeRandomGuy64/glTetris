#include "resourceManager.h"

#include <fmt/core.h>
#include <sstream>
#include <fstream>

// instantiate static variables
std::map<std::string, Shader> ResourceManager::shaders;

Shader ResourceManager::loadShader(const char* vShaderFile, const char* fShaderFile, std::string name) {
	shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile);
	return shaders[name];
}

Shader ResourceManager::getShader(std::string name) {
	return shaders[name];
}

void ResourceManager::clear() {
	// properly delete all shaders
	for (auto iter : shaders) {
		glDeleteProgram(iter.second.getId());
	}
}

Shader ResourceManager::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile) {
	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode{};
	std::string fragmentCode{};

	try {
		// open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream{};
		std::stringstream fShaderStream{};

		// read file's buffer contents into stream
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();
		
		// clost file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();

		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::exception e) {
		fmt::println("ERROR::SHADER: Failed to read shader files");
	}
	const char* vShaderCode{ vertexCode.c_str() };
	const char* fShaderCode{ fragmentCode.c_str() };

	// 2. now create shader object from source code
	Shader shader{};
	shader.compile(vShaderCode, fShaderCode);
	return shader;
}