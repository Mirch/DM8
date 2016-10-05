#include "IndexBuffer.h"

namespace DM8CLI {
	namespace graphics {

		IndexBuffer::IndexBuffer(DM8::graphics::IndexBuffer* instance)
			: DMManagedObject(instance)
		{
		}

		IndexBuffer::IndexBuffer(array<unsigned int>^ data)
		{
			pin_ptr<unsigned int> arrayPin = &data[0];
			unsigned int size = data->Length;
			m_Instance = new DM8::graphics::IndexBuffer(arrayPin, size);
		}

		void IndexBuffer::Bind()
		{
			m_Instance->Bind();
		}

		void IndexBuffer :: Unbind()
		{
			m_Instance->Unbind();
		}

	}
}