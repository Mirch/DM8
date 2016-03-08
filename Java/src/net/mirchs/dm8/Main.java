package net.mirchs.dm8;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL13.*;

import java.util.Random;

import net.mirchs.dm8.graphics.DMRenderer2D;
import net.mirchs.dm8.graphics.Shader;
import net.mirchs.dm8.graphics.Sprite;
import net.mirchs.dm8.graphics.Texture;
import net.mirchs.dm8.graphics.Window;
import net.mirchs.dm8.graphics.layers.Group;
import net.mirchs.dm8.graphics.layers.Layer;
import net.mirchs.dm8.graphics.layers.Layer2D;
import net.mirchs.dm8.input.Keyboard;
import net.mirchs.dm8.input.MousePosition;
import net.mirchs.dm8.math.Matrix4f;
import net.mirchs.dm8.math.Vector2f;
import net.mirchs.dm8.math.Vector3f;
import net.mirchs.dm8.math.Vector4f;

public class Main implements Runnable {

	private Window window;
	private Thread thread;
	private boolean running;

	private DMRenderer2D renderer;
	Shader shader, shader2;
	Layer layer, layer2;

	private Texture texture, texture2;
	private final Random random = new Random();

	public void start() {
		running = true;
		thread = new Thread(this, "Sandbox");
		thread.start();
	}

	public void init() {
		window = new Window("Sandbox", 1280, 720);

		glfwSwapInterval(0);
		glClearColor(0, 0, 0, 1);

		int[] tids = new int[] {
				0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		};

		shader = new Shader("shaders/element.vert", "shaders/element.frag");

		shader.enable();
		shader.setUniform1iv("textures", tids);
		shader.disable();

		layer = new Layer2D(shader);
		Matrix4f transform = Matrix4f.translate(new Vector3f(-4.0f, -8.0f, 0.0f)).multiply(Matrix4f.rotate(45));

		texture = new Texture("res/test1.jpg");
		texture2 = new Texture("res/test2.jpg");
		Vector2f size = new Vector2f(0.9f, 0.9f);
		Vector4f color = new Vector4f(1, 0, 1, 1);

		for (float y = 0.0f; y < 9.0f; y+=1f) {
			for (float x = 0.0f; x < 16.0f; x+=1f) {
				int t = random.nextInt(2);
				layer.add(new Sprite(new Vector3f(x, y, 0), size, (t == 0) ? texture : texture2));
			}
		}
		

	}

	public void run() {
		init();
		long lastTime = System.nanoTime();
		final double ns = 1000000000.0f / 60.0f;
		double delta = 0;
		int frames = 0, updates = 0;
		long time = System.currentTimeMillis();
		while (running) {
			long now = System.nanoTime();
			delta += (now - lastTime) / ns;
			lastTime = now;
			render();
			if (delta >= 1) {
				updates++;
				update();
				delta--;
			}
			frames++;

			if (System.currentTimeMillis() - time >= 1000) {
				System.out.println(frames + " " + updates);
				time += 1000;
				frames = 0;
				updates = 0;
			}

			if (Keyboard.isKeyDown(GLFW_KEY_ESCAPE)) {

				glfwSetWindowShouldClose(window.getID(), GL_TRUE);
			}
			if (glfwWindowShouldClose(window.getID()) == GL_TRUE) {
				running = false;

			}
		}
	}

	public void update() {
		window.update();
		int error = glGetError();
		if (error != GL_NO_ERROR) {
			System.out.println("OpenGL error: " + error);
		}

	}

	public void render() {
		window.clear();
		shader.enable();
		shader.setUniform2f("light_pos", (float) (MousePosition.getX() * 16.0f / 1280.0f), ((float) (9.0f - 9.0f * MousePosition.getY() / 720.0f)));
		shader.disable();
		
		layer.render();
	}

	public static void main(String[] args) {
		new Main().start();
	}

}
