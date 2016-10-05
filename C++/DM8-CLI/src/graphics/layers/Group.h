#pragma once

#include "../../DMManagedObject.h"
#include "../../math/Mat4.h"
#include "../Renderable2D.h"
#include "../Renderer2D.h"

namespace DM8CLI {
	namespace graphics {

		public ref class Group : DMManagedObject<DM8::graphics::Group>
		{
		private:
			Group(DM8::graphics::Group* instance);
		public:
			Group(math::Mat4^ transform);

			void Push(Renderable2D^ renderable);
			void Submit(Renderer2D^ renderer);
		};
	}
}