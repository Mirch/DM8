#include "Scene.h"



namespace DM8
{
	namespace scene
	{
		using namespace entity;
		using namespace entity::component;

		Scene::Scene(const math::Mat4& projectionMatrix)
		{
			m_Camera = new graphics::camera::Camera(projectionMatrix);
		}

		Scene::~Scene()
		{
			delete m_Camera;
			for (int i = 0; i < m_Entities.size(); i++)
				delete m_Entities[i];
		}

		void Scene::Add(entity::Entity* entity)
		{
			m_Entities.push_back(entity);
			entity->SetScene(this);
		}

		void Scene::Start()
		{
			DidStart = true;
			for (int i = 0; i < m_Entities.size(); i++)
				m_Entities[i]->Start();
		}

		void Scene::Update()
		{
			if (!DidStart)
				Start();
			for (int i = 0; i < m_Entities.size(); i++)
				m_Entities[i]->Update();
		}

		void Scene::Render(graphics::Renderer2D* renderer)
		{
			renderer->Begin();

			for (int i = 0; i < m_Entities.size(); i++)
			{
				entity::component::SpriteComponent* sc = m_Entities[i]->GetComponent<entity::component::SpriteComponent>();
				renderer->Push(m_Entities[i]->GetComponent<entity::component::TransformComponent>()->m_Transform, true);
				sc->m_Sprite->Submit(renderer);
				renderer->Pop();
			}

			renderer->End();
			renderer->Flush();

		}

		void Scene::CheckCollisions()
		{
			for (int i = 0; i < m_Entities.size(); i++)
			{
				bool isColliding = false;
				for (int j = 0; j < m_Entities.size(); j++)
				{
					if (m_Entities[i] == m_Entities[j]) continue;
					if (!m_Entities[i]->GetComponent<CollisionBox>() || !!m_Entities[j]->GetComponent<CollisionBox>()) continue;

					bool coll = m_Entities[i]->GetComponent<CollisionBox>()->Intersects(*m_Entities[j]->GetComponent<CollisionBox>());
					isColliding = isColliding || coll;
				}
				m_Entities[i]->GetComponent<CollisionBox>()->SetColliding(isColliding);
			}
		}

		void Scene::CheckCollisionsFor(entity::Entity * e1)
		{
			bool isColliding = false;
			for (int j = 0; j < m_Entities.size(); j++)
			{
				if (e1 == m_Entities[j]) continue;
				if (!e1->GetComponent<CollisionBox>() || !m_Entities[j]->GetComponent<CollisionBox>()) continue;

				bool coll = e1->GetComponent<CollisionBox>()->Intersects(*m_Entities[j]->GetComponent<CollisionBox>());
				std::cout << coll << std::endl;
				isColliding = isColliding || coll;
			}
			e1->GetComponent<CollisionBox>()->SetColliding(isColliding);
		}

		void Scene::SetCamera(graphics::camera::Camera* camera)
		{
			m_Camera = camera;
		}


	}
}