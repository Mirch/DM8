#include "Sprite.h"

namespace DM8CLI {
	namespace graphics {
	
		Sprite::Sprite(DM8::graphics::Sprite* instance)
			: Renderable2D((DM8::graphics::Renderable2D*)instance)
		{

		}

		Sprite::Sprite(math::Vec3^ position, math::Vec2^ size, Texture^ texture)
		{
			m_Instance = new DM8::graphics::Sprite(const_cast<const DM8::math::Vec3&>(*position->GetHandle()), const_cast<const DM8::math::Vec2&>(*size->GetHandle()), texture->GetHandle());
		}

		Sprite::Sprite(math::Vec3^ position, math::Vec2^ size, math::Vec4^ color)
		{
			m_Instance = new DM8::graphics::Sprite(const_cast<const DM8::math::Vec3&>(*position->GetHandle()), const_cast<const DM8::math::Vec2&>(*size->GetHandle()), const_cast<const DM8::math::Vec4&>(*color->GetHandle()));
		}

		Sprite::Sprite(math::Vec2^ size, Texture^ texture)
		{
			m_Instance = new DM8::graphics::Sprite(const_cast<const DM8::math::Vec2&>(*size->GetHandle()), texture->GetHandle());
		}

		Sprite::Sprite(math::Vec2^ size, math::Vec4^ color)
		{
			m_Instance = new DM8::graphics::Sprite(const_cast<const DM8::math::Vec2&>(*size->GetHandle()), const_cast<const DM8::math::Vec4&>(*color->GetHandle()));
		}


	}
}