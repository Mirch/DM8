#include "Game.h"

namespace DM8
{

	Game::Game(std::string name, int width, int height)
	{
		m_Window = new graphics::Window(name.c_str(), width, height);
		m_Running = true;
		Run();
	}

	Game::~Game()
	{
		for (int i = 0; i < m_Layers.size(); i++)
			delete m_Layers[i];
	}

	void Game::AddLayer(graphics::Layer* layer)
	{
		m_Layers.push_back(layer);
	}

	void Game::Run()
	{
		double lastTime = glfwGetTime();
		double dif = 1 / 60.0f;
		while (m_Running)
		{
			double now = glfwGetTime();
			if (now - lastTime >= dif)
			{
				Update();
				lastTime = now;
			}
			Render();
		}
	}

	void Game::Update()
	{
		m_ActiveScene->Update();
	}

	void Game::Render()
	{
		for (int i = 0; i < m_Layers.size(); i++)
		{
			m_Layers[i]->Render();
		}
	}


}