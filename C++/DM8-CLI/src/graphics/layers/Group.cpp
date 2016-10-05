#include "Group.h"

namespace DM8CLI {
	namespace graphics {


		Group::Group(DM8::graphics::Group* instance)
			: DMManagedObject(instance)
		{

		}

		Group::Group(math::Mat4^ transform)
		{
			m_Instance = new DM8::graphics::Group(*transform->GetHandle());
		}

		void Group::Push(Renderable2D^ renderable)
		{
			m_Instance->Push(renderable->GetHandle());
		}

		void Group::Submit(Renderer2D^ renderer)
		{
			m_Instance->Submit(renderer->GetHandle());
		}

	}
}