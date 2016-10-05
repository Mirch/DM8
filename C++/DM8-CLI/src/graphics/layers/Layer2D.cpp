#include "Layer2D.h"

namespace DM8CLI
{
	namespace graphics
	{
		Layer2D::Layer2D(DM8::graphics::Layer2D* instance)
			: Layer((DM8::graphics::Layer*)instance)
		{

		}

		Layer2D::Layer2D(Shader^ shader)
			: Layer(gcnew DMRenderer2D(), shader, math::Mat4::Ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f))
		{

		}

	}
}