#include "Layer.h"

namespace DM8 {
	namespace graphics {
	
		Layer::Layer(Renderer2D* renderer, Shader* shader, const math::Mat4& projectionMatrix)
			: m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
		{
			m_Shader->Enable();
			m_Shader->SetUniformMat4("pr_matrix", m_ProjectionMatrix);
			m_Shader->Disable();
		}

		void Layer::Push(Renderable2D* renderable)
		{
			m_Renderables.push_back(renderable);
		}

		void Layer::Render()
		{
			m_Shader->Enable();
			m_Renderer->Begin();
			for (Renderable2D* renderable : m_Renderables)
			{
				renderable->Submit(m_Renderer);
			}

			m_Renderer->Pop();
			m_Renderer->End();
			m_Renderer->Flush();
			m_Shader->Disable();
		}

	}
}