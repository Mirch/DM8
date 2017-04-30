#pragma once


#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Renderer2D.h"
#include "Renderable2D.h"
#include "buffers/IndexBuffer.h"

#include <vector>

#define MAX_SPRITES  60000
#define VERTEX_SIZE  sizeof(DM8::graphics::VertexData)
#define SPRITE_SIZE  VERTEX_SIZE * 4
#define BUFFER_SIZE  SPRITE_SIZE * MAX_SPRITES
#define INDICES_SIZE MAX_SPRITES * 6 * 4


#define SHADER_VERTEX_INDEX 0
#define SHADER_UV_INDEX     1
#define SHADER_TID_INDEX    2
#define SHADER_COLOR_INDEX  3


namespace DM8 {
	namespace graphics {

		class DMRenderer2D : public Renderer2D
		{
		private:
			GLuint m_Vao;
			IndexBuffer* m_Ibo;
			GLuint m_Vbo;
			unsigned int m_IndexCount;
			VertexData* m_Buffer;

			std::vector<int> m_TextureSlots;
		public:
			DMRenderer2D();
			~DMRenderer2D();

			void Init();

			void Begin() override;
			void End() override;
			
			void Submit(const Renderable2D* renderable) override;
			void Flush() override;

 		};


	}
}