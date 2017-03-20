#include "DMRenderer2D.h"

#include <iostream>

namespace DM8 {
	namespace graphics {

		DMRenderer2D::DMRenderer2D()
			: Renderer2D(), m_IndexCount(0)
		{
			Init();
		}

		DMRenderer2D::~DMRenderer2D()
		{
			delete m_Ibo;
			glDeleteBuffers(1, &m_Vbo);
		}

		void DMRenderer2D::Init()
		{
			glGenVertexArrays(1, &m_Vao);
			glGenBuffers(1, &m_Vbo);

			glBindVertexArray(m_Vao);
			glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
			glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_UV_INDEX);
			glEnableVertexAttribArray(SHADER_TID_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);


			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)0);
			glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::m_UV));
			glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::m_TID));
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, VERTEX_SIZE, (const GLvoid*)offsetof(VertexData, VertexData::m_Color));


			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLuint* indices = new GLuint[INDICES_SIZE];


			int offset = 0;
			for (int i = 0; i < INDICES_SIZE; i += 6)
			{
				indices[i] = offset + 0;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;

				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;

				offset += 4;
			}

			m_Ibo = new IndexBuffer(indices, INDICES_SIZE);

			delete indices;

			glBindVertexArray(0);
		}

		void DMRenderer2D::Begin()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
			m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void DMRenderer2D::Submit(const Renderable2D* sprite)
		{
			const math::Vec3& position = sprite->GetPosition();
			const math::Vec2& size = sprite->GetSize();
			const math::Vec4& color = sprite->GetColor();
			const std::vector<math::Vec2>& uv = sprite->GetUV();

			float tid = 0;

			if(sprite->IsTextured())
				tid = sprite->GetTID();

			int c = 0;
			float ts = 0.0f;

			if (tid > 0)
			{
				bool found = false;
				for (int i = 0; i < m_TextureSlots.size(); i++)
				{
					if (m_TextureSlots[i] == tid)
					{
						found = true;
						ts = (float)i + 1;
						break;
					}
				}

				if (!found)
				{
					if (m_TextureSlots.size() >= 32)
					{
						End();
						Flush();
						Begin();
					}
					m_TextureSlots.push_back(tid);
					ts = (float)m_TextureSlots.size()-1;
				}

			}
			else
			{
				int r = (int)(color.x * 255.0f);
				int g = (int)(color.y * 255.0f);
				int b = (int)(color.z * 255.0f);
				int a = (int)(color.w * 255.0f);

				c = (a << 24) | (b << 16) | (g << 8) | r;
			}

			m_Buffer->m_Position = *m_TransfBack * position;
			m_Buffer->m_UV = uv[0];
			m_Buffer->m_TID = ts;
			m_Buffer->m_Color = c;
			m_Buffer++;

			m_Buffer->m_Position = *m_TransfBack * math::Vec3(position.x, position.y + size.y, position.z);
			m_Buffer->m_UV = uv[1];
			m_Buffer->m_TID = ts;
			m_Buffer->m_Color = c;
			m_Buffer++;

			m_Buffer->m_Position = *m_TransfBack * math::Vec3(position.x + size.x, position.y + size.y, position.z);
			m_Buffer->m_UV = uv[2];
			m_Buffer->m_TID = ts;
			m_Buffer->m_Color = c;
			m_Buffer++;

			m_Buffer->m_Position = *m_TransfBack * math::Vec3(position.x + size.x, position.y, position.z);
			m_Buffer->m_UV = uv[3];
			m_Buffer->m_TID = ts;
			m_Buffer->m_Color = c;
			m_Buffer++;

			m_IndexCount += 6;

		}

		void DMRenderer2D::End()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void DMRenderer2D::Flush()
		{
			for (int i = 0; i < m_TextureSlots.size(); i++)
			{
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, m_TextureSlots[i]);
			}
			
			glBindVertexArray(m_Vao);
			m_Ibo->Bind();
			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);
			m_Ibo->Unbind();
			glBindVertexArray(0);
			m_IndexCount = 0;
		}

	}
}