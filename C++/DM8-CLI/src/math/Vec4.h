#pragma once

#include "../DMManagedObject.h"

namespace DM8CLI
{
	namespace math
	{

		public ref class Vec4 : public DMManagedObject<DM8::math::Vec4>
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

			property float z
			{
				float get()
				{
					return m_Instance->z;
				}
				void set(float value)
				{
					m_Instance->z = value;
				}
			}

			property float w
			{
				float get()
				{
					return m_Instance->w;
				}
				void set(float value)
				{
					m_Instance->w = value;
				}
			}

		
			Vec4();
			Vec4(DM8::math::Vec4* instance);
			Vec4(float x, float y, float z, float w);

			Vec4^ Add(Vec4^ other);
			Vec4^ Subtract(Vec4^ other);
			Vec4^ Multiply(Vec4^ other);
			Vec4^ Divide(Vec4^ other);

			static Vec4^ operator+(Vec4^ left, Vec4^ right);
			static Vec4^ operator-(Vec4^ left, Vec4^ right);
			static Vec4^ operator*(Vec4^ left, Vec4^ right);
			static Vec4^ operator/(Vec4^ left, Vec4^ right);

			bool operator==(Vec4^ other);
			bool operator!=(Vec4^ other);

			Vec4^ operator+=(Vec4^ other);
			Vec4^ operator-=(Vec4^ other);
			Vec4^ operator*=(Vec4^ other);
			Vec4^ operator/=(Vec4^ other);
		};
	}
}

