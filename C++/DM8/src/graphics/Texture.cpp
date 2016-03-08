#include "Texture.h"

#include "../utils/FileUtils.h"

namespace DM8 {
	namespace graphics {
			
		Texture::Texture(const char* path) :
			m_Path(path)
		{
			Load(path);
		}

		Texture::~Texture()
		{
			glDeleteTextures(1, &m_TID);
		}

		void Texture::Load(const char* path)
		{
		
			BYTE* pixels = utils::LoadImage(path, &m_Width, &m_Height, &m_Bits);

			glGenTextures(1, &m_TID);

			glBindTexture(GL_TEXTURE_2D, m_TID);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER , GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
			glBindTexture(GL_TEXTURE_2D, 0);

			if (pixels != nullptr)
				delete[] pixels;
		}

		void Texture::Bind() const
		{
			glBindTexture(GL_TEXTURE_2D, m_TID);
		}

		void Texture::Unbind() const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}


	}
}