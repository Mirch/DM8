#pragma once

#include <map>
#include "../math/DMmath.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace DM8 {
	namespace graphics {

		using namespace math;

		class Shader
		{ 
		private:
			unsigned int m_ID;
		public:
			Shader(const char* vertex, const char* fragment);
			~Shader();

			GLuint Load(const char* vertPath, const char* fragPath);
			GLuint Create(const char* vert, const char* path);

			GLint GetUniform(const char* name);

			void SetUniform1i(const char* name, int value);
			void SetUniform1iv(const char* name, int* values, int count);
			void SetUniform1f(const char* name, float value);
			void SetUniform1fv(const char* name, float* values, int count);
			void SetUniform2f(const char* name, Vec2& vector);
			void SetUniform3f(const char* name, Vec3& vector);
			void SetUniform4f(const char* name, Vec4& vector);
			void SetUniformMat4(const char* name, Mat4& matrix);

			void Enable() const;
			void Disable() const;

			static Shader* GetDefaultShader();

		};

	}
}