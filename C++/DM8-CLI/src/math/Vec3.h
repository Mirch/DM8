#pragma once

#include "../DMManagedObject.h"

namespace DM8CLI
{
	namespace math
	{

		public ref class Vec3 : public DMManagedObject<DM8::math::Vec3>
		{
		public:

			Vec3();
			Vec3(DM8::math::Vec3* instance);
			Vec3(float x, float y, float z);
		
			Vec3^ Add(Vec3^ other);
			Vec3^ Subtract(Vec3^ other);
			Vec3^ Multiply(Vec3^ other);
			Vec3^ Divide(Vec3^ other);

			static Vec3^ operator+(Vec3^ left, Vec3^ right);
			static Vec3^ operator-(Vec3^ left, Vec3^ right);
			static Vec3^ operator*(Vec3^ left, Vec3^ right);
			static Vec3^ operator/(Vec3^ left, Vec3^ right);

			bool operator==(Vec3^ other);
			bool operator!=(Vec3^ other);

			Vec3^ operator+=(Vec3^ other);
			Vec3^ operator-=(Vec3^ other);
			Vec3^ operator*=(Vec3^ other);
			Vec3^ operator/=(Vec3^ other);

		
		};

	}
}

