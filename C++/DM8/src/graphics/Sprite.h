#pragma once

#include "Renderable2D.h"

namespace DM8 {
	namespace graphics {

		class Sprite : public Renderable2D
		{
		public:
			Sprite(const math::Vec3& position, const math::Vec2& size, Texture* texture);
			Sprite(const math::Vec3& position, const math::Vec2& size, math::Vec4 color);

		};

	}
}