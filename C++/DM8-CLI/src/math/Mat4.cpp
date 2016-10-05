#include "Mat4.h"

namespace DM8CLI
{
	namespace math
	{

		Mat4::Mat4(DM8::math::Mat4* instance)
			: DMManagedObject(instance)
		{

		}

		Mat4::Mat4()
		{
			m_Instance = new DM8::math::Mat4();
		}

		Mat4^ Mat4::Identity()
		{
			return gcnew Mat4(&DM8::math::Mat4::Identity());
		}

		Mat4^ Mat4::Ortho(float left, float right, float bottom, float top, float near, float far)
		{
			return gcnew Mat4(&DM8::math::Mat4::Ortho(left, right, bottom, top, near, far));
		}

		Mat4^ Mat4::Rotate(float angle)
		{
			return gcnew Mat4(&DM8::math::Mat4::Rotate(angle));
		}

		Mat4^ Mat4::Translate(Vec3^ vector)
		{
			return gcnew Mat4(&DM8::math::Mat4::Translate(*vector->GetHandle()));
		}

		Mat4^ Mat4::Multiply(Mat4^ other)
		{
			return gcnew Mat4(&m_Instance->Multiply(*other->GetHandle()));
		}

		Mat4^ Mat4::operator*(Mat4^ left, Mat4^ right)
		{
			return left->Multiply(right);
		}

		Mat4^ Mat4::operator*=(Mat4^ other)
		{
			return Multiply(other);
		}

		Vec3^ Mat4::Multiply(Vec3^ other)
		{
			return gcnew Vec3(&m_Instance->Multiply(*other->GetHandle()));
		}

		Vec3^ Mat4::operator*(Mat4^ left, Vec3^ right)
		{
			return left->Multiply(right);
		}

		Vec4^ Mat4::Multiply(Vec4^ other)
		{
			return gcnew Vec4(&m_Instance->Multiply(*other->GetHandle()));
		}

		Vec4^ Mat4::operator*(Mat4^ left, Vec4^ right)
		{
			return left->Multiply(right);
		}


	}
}
