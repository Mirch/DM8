#pragma once

#include "../DMManagedObject.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

namespace DM8CLI
{
	 namespace math
	{

		public ref class Mat4 : public DMManagedObject<DM8::math::Mat4>
		{
		private:
			Mat4(DM8::math::Mat4* instance);
		public:
			Mat4();

			static Mat4^ Identity();

			static Mat4^ Ortho(float left, float right, float bottom, float top, float near, float far);
			static Mat4^ Rotate(float angle);
			static Mat4^ Translate(Vec3^ vector);

			Mat4^ Multiply(Mat4^ other);
			static Mat4^ operator*(Mat4^ left, Mat4^ right);
			Mat4^ operator*=(Mat4^ other);

			Vec3^ Multiply(Vec3^ other);
			static Vec3^ operator*(Mat4^ left, Vec3^ right);
			
			Vec4^ Multiply(Vec4^ other);
			static Vec4^ operator*(Mat4^ left, Vec4^ right);




		};

	}
}


