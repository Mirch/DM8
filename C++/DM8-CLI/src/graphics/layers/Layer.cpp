#include "Layer.h"


namespace DM8CLI {
	namespace graphics {

		Layer::Layer(DM8::graphics::Layer* instance)
			: DMManagedObject(instance)
		{
		}

		Layer::Layer(Renderer2D^ renderer, Shader^ shader, math::Mat4^ projectionMatrix)
		{
			DM8::math::Mat4 matrix = const_cast<const DM8::math::Mat4&>(*projectionMatrix->GetHandle());
			DM8::graphics::Renderer2D* pRenderer = renderer->GetHandle();
			DM8::graphics::Shader* pShader = shader->GetHandle();

			m_Instance = new DM8::graphics::Layer(pRenderer, pShader, matrix);
		}

		void Layer::Push(Renderable2D^ renderable)
		{
			m_Instance->Push(renderable->GetHandle());
		}

		void Layer::Render()
		{
			m_Instance->Render();
		}

	}
}