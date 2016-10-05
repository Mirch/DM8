#include "Shader.h"

namespace DM8CLI
{
	namespace graphics
	{
		using namespace System::Runtime::InteropServices;
		Shader::Shader(DM8::graphics::Shader* instance)
			: DMManagedObject(instance)
		{

		}

		Shader::Shader(String^ vertex, String^ fragment)
		{
			const char* vertexString = string_to_char_array(vertex);
			const char* fragmentString = string_to_char_array(fragment);
			m_Instance = new DM8::graphics::Shader(vertexString, fragmentString);
		}

		void Shader::SetUniform1i(String^ name, int value)
		{
			const char* nameString = string_to_char_array(name);
			m_Instance->SetUniform1i(nameString, value);
		}

		void Shader::SetUniformiv(String^ name, array<int>^ value)
		{
			const char* nameString = string_to_char_array(name);
			pin_ptr<int> valuesPtr = &value[0];
			m_Instance->SetUniform1iv(nameString, valuesPtr, value->Length);
		}

		void Shader::SetUniform1f(String^ name, float value)
		{
			const char* nameString = string_to_char_array(name);
			m_Instance->SetUniform1f(nameString, value);
		}

		void Shader::SetUniformfv(String^ name, array<float>^ value)
		{
			const char* nameString = string_to_char_array(name);
			pin_ptr<float> valuesPtr = &value[0];
			m_Instance->SetUniform1fv(nameString, valuesPtr, value->Length);
		}

		void Shader::SetUniform2f(String^ name, DM8CLI::math::Vec2^ vector)
		{
			const char* nameString = string_to_char_array(name);
			m_Instance->SetUniform2f(nameString, *vector->GetHandle());
		}

		void Shader::SetUniform3f(String^ name, DM8CLI::math::Vec3^ vector)
		{
			const char* nameString = string_to_char_array(name);
			m_Instance->SetUniform3f(nameString, *vector->GetHandle());
		}

		void Shader::SetUniform4f(String^ name, DM8CLI::math::Vec4^ vector)
		{
			const char* nameString = string_to_char_array(name);
			m_Instance->SetUniform4f(nameString, *vector->GetHandle());
		}

		void Shader::SetUniformMat4(String^ name, DM8CLI::math::Mat4^ matrix)
		{
			const char* nameString = string_to_char_array(name);
			m_Instance->SetUniformMat4(nameString, *matrix->GetHandle());
		}

		void Shader::Enable()
		{
			m_Instance->Enable();
		}

		void Shader::Disable()
		{
			m_Instance->Disable();
		}

	}
}