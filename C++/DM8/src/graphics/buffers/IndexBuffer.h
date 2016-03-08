#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace DM8 {
	namespace graphics {

		class IndexBuffer
		{
		private:
			GLuint m_ID;
			unsigned int m_Count;
		public:
			IndexBuffer(unsigned short* data, unsigned int count);

			void Bind() const;
			void Unbind() const;

			inline const unsigned int& GetCount() const { return m_Count; };

		};

	}
}