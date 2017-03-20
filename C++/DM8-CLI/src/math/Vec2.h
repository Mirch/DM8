#pragma once

#include "../DMManagedObject.h"

namespace DM8CLI
{
	namespace math
	{

		public ref class Vec2 : public DMManagedObject<DM8::math::Vec2>
		{
		public:

			property float x
			{
				float get()
				{
					return m_Instance->x;
				}
				void set(float value)
				{
					m_Instance->x = value;
				}
			}

			property float y
			{
				float get()
				{
					return m_Instance->y;
				}
				void set(float value)
				{
					m_Instance->y = value;
				}
			}

			Vec2();
			Vec2(DM8::math::Vec2* instance);
			Vec2(float x, float y);
			
			Vec2^ Add(Vec2^ other);
			Vec2^ Subtract(Vec2^ other);
			Vec2^ Multiply(Vec2^ other);
			Vec2^ Divide(Vec2^ other);

			static Vec2^ operator+(Vec2^ left, Vec2^ right);
			static Vec2^ operator-(Vec2^ left, Vec2^ right);
			static Vec2^ operator*(Vec2^ left, Vec2^ right);
			static Vec2^ operator/(Vec2^ left, Vec2^ right);

			bool operator==(Vec2^ other);
			bool operator!=(Vec2^ other);

			Vec2^ operator+=(Vec2^ other);
			Vec2^ operator-=(Vec2^ other);
			Vec2^ operator*=(Vec2^ other);
			Vec2^ operator/=(Vec2^ other);
			

		};

	}
}


