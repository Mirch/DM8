#pragma once

#include "../DMManagedObject.h"

namespace DM8CLI
{
	namespace graphics 
	{
	using namespace System;
		public ref class Texture : public DMManagedObject<DM8::graphics::Texture>
		{
		private:
			Texture(DM8::graphics::Texture* instance);
		public:
			Texture(String^ path);

			void Load(String^ path);

			void Bind();
			void Unbind();

			inline unsigned int GetWidth() { return m_Instance->GetWidth(); };
			inline unsigned int GetHeight() { return m_Instance->GeHeight(); };


		};
	}
}
