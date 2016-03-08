#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Buffer.h"

namespace DM8 {
	namespace graphics {

		class VertexArray
		{
		private:
			GLuint m_ID;
			std::vector<Buffer*> m_Buffers;
		public:
			VertexArray();
			~VertexArray();

			void Bind() const;
			void Unbind() const;

		};


	}
}