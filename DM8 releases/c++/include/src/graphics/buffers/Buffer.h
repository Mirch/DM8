#pragma once

#include <GL/glew.h>
#include <GLFW\glfw3.h>

namespace DM8 {
	namespace graphics {

		class Buffer
		{
		private:
			GLuint m_ID;
			unsigned int m_ComponentCount;
		public:
			Buffer(float* data, int count, unsigned int componentCount);

			void Bind() const;
			void Unbind() const;

			inline unsigned int GetComponentCount() { return m_ComponentCount; };
		};

	}
}