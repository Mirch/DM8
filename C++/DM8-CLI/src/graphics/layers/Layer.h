#pragma once

#include "../../DMManagedObject.h"
#include "../Renderer2D.h"
#include "../Shader.h"
#include "../Renderable2D.h"

namespace DM8CLI {
	namespace graphics {

		public ref class Layer : public DMManagedObject<DM8::graphics::Layer>
		{
		protected:
			Layer(DM8::graphics::Layer* instance);
		public:
			Layer(Renderer2D^ renderer, Shader^ shader, math::Mat4^ projectionMatrix);

			void Push(Renderable2D^ renderable);
			void Render();
		};
	}
}