#pragma once

#include "../DMManagedObject.h"
#include "../math/Vec2.h"
#include "../math/Vec3.h"
#include "../math/Vec4.h"
#include "../math/Mat4.h"


using namespace System;

namespace DM8CLI
{
	namespace graphics
	{
		public ref class Shader : public DMManagedObject<DM8::graphics::Shader>
		{
		private:
			Shader(DM8::graphics::Shader* instance);
		public:
			Shader(String^ vertex, String^ fragment);

			void SetUniform1i(String^ name, int value);
			void SetUniformiv(String^ name, array<int>^ value);
			void SetUniform1f(String^ name, float value);
			void SetUniformfv(String^ name, array<float>^ value);
			void SetUniform2f(String^ name, DM8CLI::math::Vec2^ vector);
			void SetUniform3f(String^ name, DM8CLI::math::Vec3^ vector);
			void SetUniform4f(String^ name, DM8CLI::math::Vec4^ vector);
			void SetUniformMat4(String^ name, DM8CLI::math::Mat4^ matrix);

			void Enable();
			void Disable();


		};
	}
}