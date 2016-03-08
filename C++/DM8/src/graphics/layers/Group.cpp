#include "Group.h"


namespace DM8 {
	namespace graphics {
			
		Group::Group(const math::Mat4& transform)
			:m_TransformationMatrix(transform)
		{

		}

		Group::~Group()
		{
			for (int i = 0; i <= m_Renderables.size(); i++)
				delete m_Renderables[i];
		}

		void Group::Push(Renderable2D* renderable)
		{
			m_Renderables.push_back(renderable);
		}

		void Group::Submit(Renderer2D* renderer)
		{
			renderer->Push(m_TransformationMatrix);
			for (Renderable2D* renderable : m_Renderables) {
				renderable->Submit(renderer);
			}
			renderer->Pop();
		}

	}
}