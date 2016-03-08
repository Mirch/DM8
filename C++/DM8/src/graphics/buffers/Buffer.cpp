#include "Buffer.h"


namespace DM8 {
	namespace graphics {

		Buffer::Buffer(float* data, int count, unsigned int componentCount) :
			m_ComponentCount(componentCount)
		{
			glGenBuffers(1, &m_ID);
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
			glBufferData(GL_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Buffer::Bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		}

		void Buffer::Unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

	}
}