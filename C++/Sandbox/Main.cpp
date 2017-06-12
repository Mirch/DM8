#include "../DM8/DM8.h"

#include "SquareBehaviour.h"


using namespace DM8;

int main()
{
	Game game("Test", 1280, 720);

	graphics::Shader* shader = new graphics::Shader("shaders/shader.vert", "shaders/shader.frag");
	graphics::Sprite* sprite = new graphics::Sprite(math::Vec3(0, 0, 0), math::Vec2(1, 1), math::Vec4(1, 0.5f, 1, 1));
	graphics::Sprite* wallSprite = new graphics::Sprite(math::Vec3(7, 3, 0), math::Vec2(1, 5), math::Vec4(0, 0.5f, 1, 1));

	entity::Entity* square = new entity::Entity("Square", sprite);
	entity::Entity* wall = new entity::Entity("Wall", wallSprite);

	square->AddComponent(new SquareBehaviour("SquareBehaviour", square));
	square->AddComponent(new RigidBody2D(square));

	scene::Scene* scene = new scene::Scene(math::Mat4::Ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));

	scene->Add(square);
	scene->Add(wall);

	graphics::Layer2D* layer = new graphics::Layer2D(shader, scene);

	game.AddLayer(layer);
	game.Start();
}