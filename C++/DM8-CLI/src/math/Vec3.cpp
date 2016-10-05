#include "Vec3.h"

namespace DM8CLI
{
	namespace math
	{

		Vec3::Vec3()
			: DMManagedObject()
		{

		}

		Vec3::Vec3(DM8::math::Vec3* instance)
			: DMManagedObject(instance)
		{

		}

		Vec3::Vec3(float x, float y, float z)
		{
			m_Instance = new DM8::math::Vec3(x, y, z);
		}

		Vec3^ Vec3::Add(Vec3^ other)
		{
			return gcnew Vec3(&m_Instance->Add(*other->GetHandle()));
		}

		Vec3^ Vec3::Subtract(Vec3^ other)
		{
			return gcnew Vec3(&m_Instance->Subtract(*other->GetHandle()));
		}

		Vec3^ Vec3::Multiply(Vec3^ other)
		{
			return gcnew Vec3(&m_Instance->Multiply(*other->GetHandle()));
		}

		Vec3^ Vec3::Divide(Vec3^ other)
		{
			return gcnew Vec3(&m_Instance->Divide(*other->GetHandle()));
		}

		Vec3^ Vec3::operator+(Vec3^ left, Vec3^ right)
		{
			return left->Add(right);
		}

		Vec3^ Vec3::operator-(Vec3^ left, Vec3^ right)
		{
			return left->Subtract(right);
		}

		Vec3^ Vec3::operator*(Vec3^ left, Vec3^ right)
		{
			return left->Multiply(right);
		}


		Vec3^ Vec3::operator/(Vec3^ left, Vec3^ right)
		{
			return left->Divide(right);
		}

		bool Vec3::operator==(Vec3^ other)
		{
			return *m_Instance == *other->GetHandle();
		}

		bool Vec3::operator!=(Vec3^ other)
		{
			return *m_Instance != *other->GetHandle();
		}

		Vec3^ Vec3::operator+=(Vec3^ other)
		{
			return Add(other);
		}

		Vec3^ Vec3::operator-=(Vec3^ other)
		{
			return Subtract(other);
		}

		Vec3^ Vec3::operator*=(Vec3^ other)
		{
			return Multiply(other);
		}

		Vec3^ Vec3::operator/=(Vec3^ other)
		{
			return Divide(other);
		}

	}
}
