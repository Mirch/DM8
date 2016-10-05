#pragma once

#include "../DMManagedObject.h"
#include "../math/Vec2.h"
#include "../math/Vec3.h"
#include "../math/Vec4.h"
#include "Texture.h"
#include "Renderer2D.h"

namespace DM8CLI {
	namespace graphics {

		public ref class Renderable2D : DMManagedObject<DM8::graphics::Renderable2D>
		{
		protected:
			Renderable2D(DM8::graphics::Renderable2D* instance)
				: DMManagedObject(instance)
			{
			}
		public:
			Renderable2D()
				:DMManagedObject()
			{

			}
			Renderable2D(math::Vec3^ position, math::Vec2^ size, math::Vec4^ color)
			{
				m_Instance = new DM8::graphics::Renderable2D(*position->GetHandle(), *size->GetHandle(), *color->GetHandle());
			}

			Renderable2D(math::Vec3^ position, math::Vec2^ size, graphics::Texture^ texture)
			{
				m_Instance = new DM8::graphics::Renderable2D(const_cast<DM8::math::Vec3&>(*position->GetHandle()), const_cast<DM8::math::Vec2&>(*size->GetHandle()), texture->GetHandle());
			}

			virtual void Submit(Renderer2D^ renderer)
			{
				renderer->Submit(this);
			}

			inline void SetUVDefaults() { m_Instance->SetUVDefaults(); };

			inline math::Vec2^ GetSize() { return gcnew math::Vec2(const_cast<DM8::math::Vec2*>(&m_Instance->GetSize())); };
			inline math::Vec3^ GetPosition() { return gcnew math::Vec3(const_cast<DM8::math::Vec3*>(&m_Instance->GetPosition())); };
			inline math::Vec4^ GetColor() { return gcnew math::Vec4(const_cast<DM8::math::Vec4*>(&m_Instance->GetColor())); };
			inline bool IsTextured() { return m_Instance->IsTextured(); };


		};

	}
}