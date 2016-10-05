#include "MBuffer.h"

namespace DM8CLI {
	namespace graphics {

		MBuffer::MBuffer(DM8::graphics::Buffer* instance)
			: DMManagedObject(instance)
		{
		}

		MBuffer::MBuffer(array<float>^ data, unsigned int componentCount)
		{
			pin_ptr<float> arrayPin = &data[0];
			int size = data->Length;
			m_Instance = new DM8::graphics::Buffer(arrayPin, size, componentCount);
		}

		void MBuffer::Bind()
		{
			m_Instance->Bind();
		}

		void MBuffer::Unbind()
		{
			m_Instance->Unbind();
		}

	}
}