#include "Shader.h"
#include "../utils/FileUtils.h"

#include <GL/glew.h>
#include <GLFW\glfw3.h>

#include <vector>

namespace DM8 {
	namespace graphics {

		using namespace utils;

		Shader::Shader(const char* vertex, const char* fragment)
		{
			m_ID = Load(vertex, fragment);
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ID);
		}

		GLuint Shader::Load(const char* vertPath, const char* fragPath)
		{
			std::string v = ReadFile(vertPath);
			std::string f = ReadFile(fragPath);

			const char* vert = v.c_str();
			const char* frag = f.c_str();

			return Create(vert, frag);
		}

		GLuint Shader::Create(const char* vert, const char* frag)
		{
			GLuint program = glCreateProgram();
			GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);

			glShaderSource(vertID, 1, &vert, NULL);
			glShaderSource(fragID, 1, &frag, NULL);


			GLint result;

			glCompileShader(vertID);
			glGetShaderiv(vertID, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertID, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertID, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader!" << std::endl;
				std::cout << &error[0] << std::endl;
			}

			glCompileShader(fragID);
			glGetShaderiv(fragID, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragID, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragID, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader!" << std::endl;
				std::cout << &error[0] << std::endl;
			}

			glAttachShader(program, vertID);
			glAttachShader(program, fragID);
			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertID);
			glDeleteShader(fragID);

			return program;
		}

		GLint Shader::GetUniform(const char* name)
		{
			return glGetUniformLocation(m_ID, name);
		}

		void Shader::SetUniform1i(const char* name, int value)
		{
			glUniform1i(GetUniform(name), value);
		}

		void Shader::SetUniform1iv(const char* name, int* values, int count)
		{
			glUniform1iv(GetUniform(name), count, values);
		}

		void Shader::SetUniform1f(const char* name, float value)
		{
			glUniform1f(GetUniform(name), value);
		}

		void Shader::SetUniform1fv(const char* name, float* values, int count)
		{
			glUniform1fv(GetUniform(name), count, values);
		}

		void Shader::SetUniform2f(const char* name, Vec2& vector)
		{
			glUniform2f(GetUniform(name), vector.x, vector.y);
		}

		void Shader::SetUniform3f(const char* name, Vec3& vector)
		{
			glUniform3f(GetUniform(name), vector.x, vector.y, vector.z);
		}

		void Shader::SetUniform4f(const char* name, Vec4& vector)
		{
			glUniform4f(GetUniform(name), vector.x, vector.y, vector.z, vector.w);
		}

		void Shader::SetUniformMat4(const char* name, Mat4& matrix)
		{
			glUniformMatrix4fv(GetUniform(name), 1, GL_FALSE, matrix.elements);
		}

		void Shader::Enable() const
		{
			glUseProgram(m_ID);
		}

		void Shader::Disable() const
		{
			glUseProgram(0);
		}

	}
}