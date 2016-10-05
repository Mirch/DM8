#pragma once

#include "../DMManagedObject.h"
#include "Renderable2D.h"

namespace DM8CLI {
	namespace graphics {

		public ref class DMRenderer2D : public Renderer2D
		{
		private:
			DMRenderer2D(DM8::graphics::DMRenderer2D* instance);
		public:
			DMRenderer2D();

			void Init();

			void Begin() override;
			void End() override;

			void Submit(Renderable2D^ renderable) override;
			void Flush() override;
		};

	}
}