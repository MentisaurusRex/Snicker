#pragma once
#include <string>
#include <GL/glew.h>
namespace Snicker {
	class GLSLProgram
	{
	public:
		GLSLProgram();
		~GLSLProgram();

		void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
		void linkShaders();
		void addAttribute(const std::string attributeName);

		GLint getUniformLocation(const std::string& uniformName);

		void use();
		void unuse();

	private:
		void compileShader(const std::string& filePath, GLuint id);

		int _numOfAttributes = 0;
		GLuint _programID = 0;
		GLuint _vertexShaderID = 0;
		GLuint _fragmentShaderID = 0;
	};
}

