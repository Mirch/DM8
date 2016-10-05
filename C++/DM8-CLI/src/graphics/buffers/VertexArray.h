#pragma once

#include "../../DMManagedObject.h"

namespace DM8CLI {
	namespace graphics {

		public ref class VertexArray : public DMManagedObject<DM8::graphics::VertexArray>
		{
		private:
			VertexArray(DM8::graphics::VertexArray* instance);
		public:
			VertexArray();

			void Bind();
			void Unbind();
		};

	}
}