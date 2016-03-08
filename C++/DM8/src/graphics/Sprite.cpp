#include "Sprite.h"

namespace DM8 {
	namespace graphics {


		Sprite::Sprite(const math::Vec3& position, const math::Vec2& size, Texture* texture) :
			Renderable2D(position, size, texture)
		{
			m_Color = math::Vec4(1, 0, 1, 1);
		}

		Sprite::Sprite(const math::Vec3& position, const math::Vec2& size, math::Vec4 color) :
			Renderable2D(position, size, color)
		{

		}

	}
}