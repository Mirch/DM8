#pragma once

#include "../graphics/Window.h"
#include "../graphics/layers/Layer.h"
#include "../utils/Time.h"


#include <vector>
#include <string>
#include <algorithm>

namespace DM8
{
	class Game
	{
	private:
		graphics::Window* m_Window;
		std::vector<graphics::Layer*> m_Layers;
		scene::Scene* m_ActiveScene;

		bool m_Running;
	public:
		Game(std::string name, int width, int height);
		~Game();

		void Start();

		void AddLayer(graphics::Layer* layer);
		void ActivateScene(scene::Scene* scene);

		void Run();

	private:
		void Render();
		void Update();

	};
}