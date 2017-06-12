#include "Game.h"

namespace DM8
{

	Game::Game(std::string name, int width, int height)
	{
		m_Window = new graphics::Window(name.c_str(), width, height);
		m_Running = true;
	}

	Game::~Game()
	{
		for (int i = 0; i < m_Layers.size(); i++)
			delete m_Layers[i];
	}

	void Game::Start()
	{
		Run();
	}

	void Game::AddLayer(graphics::Layer* layer)
	{
		m_Layers.push_back(layer);
	}

	void Game::ActivateScene(scene::Scene * scene)
	{
		m_ActiveScene = scene;
	}

	void Game::Run()
	{
		double lastTime = glfwGetTime();
		double dif = 1 / 60.0f;
		while (!m_Window->IsClosed())
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
		m_Window->Update();
		Time::Update();
		for (int i = 0; i < m_Layers.size(); i++)
		{
			m_Layers[i]->Update();
		}
	}

	void Game::Render()
	{
		m_Window->Clear();

		for (int i = 0; i < m_Layers.size(); i++)
		{
			m_Layers[i]->Render();
		}
	}


}