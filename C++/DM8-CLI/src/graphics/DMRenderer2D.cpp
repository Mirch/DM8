#include "DMRenderer2D.h"

namespace DM8CLI {
	namespace graphics {

		DMRenderer2D::DMRenderer2D(DM8::graphics::DMRenderer2D* instance)
			: Renderer2D((DM8::graphics::Renderer2D*)instance)
		{
		}

		DMRenderer2D::DMRenderer2D()
			: Renderer2D()
		{
			m_Instance = new DM8::graphics::DMRenderer2D();
		}

		void DMRenderer2D::Init()
		{
			((DM8::graphics::DMRenderer2D*)m_Instance)->Init();
		}

		void DMRenderer2D::Begin()
		{
			m_Instance->Begin();
		}

		void DMRenderer2D::End()
		{
			m_Instance->End();
		}

		void DMRenderer2D::Submit(Renderable2D^ renderable)
		{
			m_Instance->Submit(renderable->GetHandle());
		}

		void DMRenderer2D::Flush()
		{
			m_Instance->Flush();
		}

	}
}