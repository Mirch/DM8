#include "Layer.h"


namespace DM8CLI {
	namespace graphics {

		Layer::Layer(DM8::graphics::Layer* instance)
			: DMManagedObject(instance)
		{
		}

		Layer::Layer(Renderer2D^ renderer, Shader^ shader, math::Mat4^ projectionMatrix)
		{
			// hard coded
			//DM8::math::Mat4 matrix = DM8::math::Mat4::Ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
			DM8::graphics::Renderer2D* pRenderer = renderer->GetHandle();
			DM8::graphics::Shader* pShader = shader->GetHandle();
			std::cout << "cur" << std::endl;
			DM8::math::Mat4* matrixTest = projectionMatrix->GetHandle();


			m_Instance = new DM8::graphics::Layer(pRenderer, pShader, *matrixTest);
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