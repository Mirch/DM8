#include "Scene.h"



namespace DM8
{
	namespace graphics
	{
		namespace scene
		{
			Scene::Scene(const math::Mat4& projectionMatrix)
			{
				m_Camera = new camera::Camera(projectionMatrix);
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
			}

			void Scene::Update()
			{
				for (int i = 0; i < m_Entities.size(); i++)
					m_Entities[i]->Update();
			}

			void Scene::Render(graphics::Renderer2D* renderer)
			{
				renderer->Begin();

				for (int i = 0; i < m_Entities.size(); i++)
				{
					m_Entities[i]->GetComponent<entity::component::SpriteComponent>()->m_Sprite->Submit(renderer);
				}

				renderer->Pop();
				renderer->End();
				renderer->Flush();

			}

			void Scene::SetCamera(camera::Camera* camera)
			{
				m_Camera = camera;
			}


		}
	}
}