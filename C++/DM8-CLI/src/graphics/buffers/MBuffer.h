#pragma once

#include "../../DMManagedObject.h"

namespace DM8CLI {
	namespace graphics {

		public ref class MBuffer : public DMManagedObject<DM8::graphics::Buffer>
		{
		private:
			MBuffer(DM8::graphics::Buffer* instance);
		public:
			MBuffer(array<float>^ data, unsigned int componentCount);

			void Bind();
			void Unbind();

			inline unsigned int GetComponentCount() { return m_Instance->GetComponentCount(); };
			
		};
	}
}

