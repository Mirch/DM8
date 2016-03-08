#pragma once


#include <FreeImage.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace DM8 {
	namespace graphics {

		class Texture
		{
		private:
			unsigned int m_Width, m_Height;
			unsigned int m_Bits;
			const char* m_Path;
			GLuint m_TID;
		public:
			Texture(const char* path);
			~Texture();

			void Load(const char* path);

			void Bind() const;
			void Unbind() const;

			inline const unsigned int& GetWidth() const { return m_Width; };
			inline const unsigned int& GeHeight() const { return m_Height;};
			inline const GLuint& GetTID() const { return m_TID; };

		};

	}
}
