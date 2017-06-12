#include "SquareBehaviour.h"


SquareBehaviour::SquareBehaviour(std::string name, Entity* entity)
	:EntityBehaviour(name, entity)
{

}

void SquareBehaviour::Start()
{

}

void SquareBehaviour::Update()
{
	float moveX = 0.0f;
	float moveY = 0.0f;
	bool rotate = false;

	if (Input::IsKeyPressed(GLFW_KEY_A)) moveX = -0.5f;
	else if (Input::IsKeyPressed(GLFW_KEY_D)) moveX = 0.5f;

	if (Input::IsKeyPressed(GLFW_KEY_W)) moveY = 0.5f;
	else if (Input::IsKeyPressed(GLFW_KEY_S)) moveY = -0.5f;

	if (Input::IsKeyPressed(GLFW_KEY_SPACE)) rotate = true;

	EntityObject->GetComponent<RigidBody2D>()->AddForce(math::Vec2(moveX, moveY));

	if (rotate)
		EntityObject->Transform->Rotate(2.0f);

}
