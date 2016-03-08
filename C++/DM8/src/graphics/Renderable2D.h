#pragma once

#include <vector>

#include "../math/DMmath.h"
#include "Renderer2d.h"
#include "Texture.h"

namespace DM8 {
	namespace graphics {


		struct VertexData
		{
			math::Vec3 m_Position;
			math::Vec2 m_UV;
			float m_TID;
			int m_Color;
		};

		class Renderable2D
		{
		protected:
			math::Vec2 m_Size;
			math::Vec3 m_Position;
			math::Vec4 m_Color;
			std::vector<math::Vec2> m_UV;
			Texture* m_Texture;
		protected:
			Renderable2D();
		public:
			Renderable2D(const math::Vec3& position, const math::Vec2& size, math::Vec4 color)
				: m_Size(size), m_Position(position), m_Color(color)
			{
				SetUVDefaults();
			}

			Renderable2D(const math::Vec3& position, const math::Vec2& size, Texture* texture)
				: m_Size(size), m_Position(position), m_Texture(texture)
			{
				SetUVDefaults();
			}

			virtual void Submit(Renderer2D* renderer) const
			{
				renderer->Submit(this);
			}

			void SetUVDefaults()
			{
				m_UV.push_back(math::Vec2(0, 0));
				m_UV.push_back(math::Vec2(0, 1));
				m_UV.push_back(math::Vec2(1, 1));
				m_UV.push_back(math::Vec2(1, 0));
			}


			inline const std::vector<math::Vec2>& GetUV() const { return m_UV; };

			inline const math::Vec2& GetSize() const { return m_Size; };
			inline const math::Vec3& GetPosition() const { return m_Position; };
			inline const math::Vec4& GetColor() const { return m_Color; };
			inline const float& GetTID() const { return (float)(m_Texture->GetTID()); };

		};


	}
}