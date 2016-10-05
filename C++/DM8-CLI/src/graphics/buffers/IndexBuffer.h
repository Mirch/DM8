#pragma once

#include "../../DMManagedObject.h"

namespace DM8CLI {
	namespace graphics {


		public ref class IndexBuffer : public DMManagedObject<DM8::graphics::IndexBuffer>
		{
		private:
			IndexBuffer(DM8::graphics::IndexBuffer* instance);
		public:
			IndexBuffer(array<unsigned int>^ data);

			void Bind();
			void Unbind();

			inline unsigned int GetCount() { return m_Instance->GetCount(); };
		};
	}
}
