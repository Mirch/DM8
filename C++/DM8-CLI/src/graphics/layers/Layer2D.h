#pragma once

#include "Layer.h"
#include "../Shader.h"
#include "../DMRenderer2D.h"
#include "../../math/Mat4.h"

namespace DM8CLI
{
	namespace graphics
	{
		public ref class Layer2D : public Layer
		{
		private:
			Layer2D(DM8::graphics::Layer2D* instance);
		public:
			Layer2D(Shader^ shader);
		};
	}
}