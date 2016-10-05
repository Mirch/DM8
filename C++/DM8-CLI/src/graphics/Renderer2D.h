#pragma once

#include "../DMManagedObject.h"
#include "../math/Mat4.h"

namespace DM8CLI
{
	namespace graphics
	{
		ref class Renderable2D;

		public ref class Renderer2D : DMManagedObject<DM8::graphics::Renderer2D>
		{
		protected:
			Renderer2D(DM8::graphics::Renderer2D* instance)
				: DMManagedObject(instance)
			{
			}

			Renderer2D()
				: DMManagedObject()
			{
			}
		public:
			void Push(math::Mat4^ matrix, bool over)
			{
				m_Instance->Push(*matrix->GetHandle(), over);
			}

			void Push(math::Mat4^ matrix)
			{
				Push(matrix, false);
			}

			void Pop()
			{
				m_Instance->Pop();
			}

			virtual void Begin() {}
			virtual void End() {}

			virtual void Submit(Renderable2D^ renderable) {}

			virtual void Flush() {}



		};
	}
}