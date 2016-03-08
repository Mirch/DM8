#pragma once

#include "Layer.h"
#include "../Shader.h"
#include "../DMRenderer2D.h"

namespace DM8 {
	namespace graphics {

		class Layer2D : public Layer 
		{
		public:
			Layer2D(Shader* shader)
				: Layer(new DMRenderer2D(), shader, Mat4::Ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f))
			{

			}
		};

	}
}