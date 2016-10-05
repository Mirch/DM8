#include "VertexArray.h"

namespace DM8CLI {
	namespace graphics {

		VertexArray::VertexArray(DM8::graphics::VertexArray* instance)
			: DMManagedObject(instance)
		{
		}

		VertexArray::VertexArray()
		{
			m_Instance = new DM8::graphics::VertexArray();
		}

		void VertexArray::Bind()
		{
			m_Instance->Bind();
		}

		void VertexArray::Unbind()
		{
			m_Instance->Unbind();
		}

	}
}
