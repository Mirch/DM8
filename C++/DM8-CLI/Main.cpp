using namespace System;

#include "src/graphics/Window.h"
#include "src/graphics/Sprite.h"
#include "src/graphics/Shader.h"
#include "src/graphics/layers/Layer2D.h"
#include "src/math/Vec2.h"
#include "src/math/Vec3.h"

#define DEBUG_MANAGED 1



int main(array<String^> ^args)
{

#if DEBUG_MANAGED
	using namespace DM8CLI::graphics;
	using namespace DM8CLI::math;
	using namespace DM8;

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

#else 
	using namespace DM8;
	using namespace graphics;
	using namespace math;


	Window window("DM8", 1280, 720);
	glfwSwapInterval(0);
	int tids[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
	};


	Shader* shader = new Shader("shaders/shader.vert", "shaders/shader.frag");

	shader->Enable();
	shader->SetUniform1iv("textures", tids, 12);
	shader->Disable();

	Layer2D layer(shader);

	Texture* texture1 = new Texture("res/test1.jpg");
	Texture* texture2 = new Texture("res/test2.jpg");

	Vec2 size(0.9f, 0.9f);

	srand(time(0));
	for (float y = 0.0f; y < 9.0f; y += 1.0f) {
		for (float x = 0.0f; x < 16.0f; x += 1.0f) {
			int t = rand() % 2;
			Sprite* sprite = new Sprite(Vec3(x, y, 0), size, t ? texture1 : texture2);
			layer.Push(sprite);
		}
	}





	float timer = glfwGetTime();
	unsigned int frames = 0;
	while (!window.IsClosed())
	{

		window.Update();
		window.Clear();
		shader->Enable();
		shader->SetUniform2f("light_pos", Vec2((window.getMouseX() * 16.0f / 1280.0f), ((float)(9.0f - 9.0f * window.getMouseY() / 720.0f))));

		layer.Render();
		frames++;
		if (glfwGetTime() - timer > 1.0f)
		{
			timer++;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
#endif

}