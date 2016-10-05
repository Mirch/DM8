#pragma once

#include "../DMManagedObject.h"

namespace DM8CLI
{
	namespace math
	{

		public ref class Vec4 : public DMManagedObject<DM8::math::Vec4>
		{
		public:
		
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

