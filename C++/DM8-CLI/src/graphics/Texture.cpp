#include "Texture.h"

namespace DM8CLI
{
	namespace graphics
	{
		using namespace System::Runtime::InteropServices;
		Texture::Texture(DM8::graphics::Texture* instance)
			: DMManagedObject(instance)
		{

		}

		Texture::Texture(String^ path)
		{
			const char* pathString = string_to_char_array(path);
			m_Instance = new DM8::graphics::Texture(pathString);
		}

		void Texture::Load(String^ path)
		{
			const char* pathString = string_to_char_array(path);
			m_Instance->Load(pathString);
		}

		void Texture::Bind()
		{
			m_Instance->Bind();
		}

		void Texture::Unbind()
		{
			m_Instance->Unbind();
		}

	}
}