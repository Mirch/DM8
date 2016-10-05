#pragma once

#include "../DMManagedObject.h"
#include "Renderable2D.h"

namespace DM8CLI {
	namespace graphics {

		public ref class Sprite : public Renderable2D
		{
		private:
			Sprite(DM8::graphics::Sprite* instance);
		public:
			Sprite(math::Vec3^ position, math::Vec2^ size, Texture^ texture);
			Sprite(math::Vec3^ position, math::Vec2^ size, math::Vec4^ color);
			Sprite(math::Vec2^ size, Texture^ texture);
			Sprite(math::Vec2^ size, math::Vec4^ color);
		};
	}
}