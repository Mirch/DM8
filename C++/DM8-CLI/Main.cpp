using namespace System;

#include "src/graphics/Window.h"
#include "src/graphics/Sprite.h"
#include "src/graphics/Shader.h"
#include "src/graphics/layers/Layer2D.h"
#include "src/math/Vec2.h"
#include "src/math/Vec3.h"



int main(array<String^> ^args)
{
	using namespace DM8CLI::graphics;
	using namespace DM8CLI::math;

	Window window("Test", 1280, 720);
	glfwSwapInterval(0);

	array<int>^ tids = gcnew array<int>{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
	};

	Shader^ shader = gcnew Shader("shaders/shader.vert", "shaders/shader.frag");

	shader->Enable();
	shader->SetUniformiv("textures", tids);
	shader->Disable();

	Layer2D layer(shader);

	Texture^ texture1 = gcnew Texture("res/test1.jpg");
	Texture^ texture2 = gcnew Texture("res/test2.jpg");

	Vec2^ size = gcnew Vec2(0.9f, 0.9f);

	for (float y = 0.0f; y < 9.0f; y += 1.0f) {
		for (float x = 0.0f; x < 16.0f; x += 1.0f) {
			Sprite^ sprite = gcnew Sprite(gcnew Vec3(x, y, 0), size, texture1);
			layer.Push(sprite);
		}
	}

	while (!window.IsClosed())
	{
		window.Update();
		window.Clear();
		shader->Enable();
		shader->SetUniform2f("light_pos", gcnew Vec2((window.GetMouseX() * 16.0f / 1280.0f), ((float)(9.0f - 9.0f * window.GetMouseY() / 720.0f))));
		layer.Render();
	}
}