#include "VertexArray.h"


namespace DM8 {
	namespace graphics {

		VertexArray::VertexArray() 
		{
			glGenVertexArrays(1, &m_ID);
		}

		VertexArray::~VertexArray()
		{
			for (int i = 0; i < m_Buffers.size(); i++)
				delete m_Buffers[i];
		}

		void VertexArray::Bind() const
		{
			glBindVertexArray(m_ID);
		}

		void VertexArray::Unbind() const
		{
			glBindVertexArray(0);
		}


	}
}