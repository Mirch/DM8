package net.mirchs.dm8.graphics;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.system.MemoryUtil.*;

import java.nio.ByteBuffer;

import org.lwjgl.glfw.GLFWKeyCallback;
import org.lwjgl.glfw.GLFWvidmode;
import org.lwjgl.opengl.GL;
import org.lwjgl.opengl.GLContext;

import net.mirchs.dm8.input.Keyboard;
import net.mirchs.dm8.input.Mouse;
import net.mirchs.dm8.input.MousePosition;

public class Window {

	public static String TITLE;
	public static int WIDTH;
	public static int HEIGHT;
	private long ID;

	private Keyboard keyboard;
	private Mouse mouse;
	private MousePosition mousePosition;

	public Window(String title, int width, int height) {
		this.WIDTH = width;
		this.HEIGHT = height;
		this.TITLE = title;
		if (!init()) {
			return;
		}

		glfwSetKeyCallback(ID, keyboard = new Keyboard());
		glfwSetMouseButtonCallback(ID, mouse = new Mouse());
		glfwSetCursorPosCallback(ID, mousePosition = new MousePosition());

	}

	public boolean init() {
		if (glfwInit() == GL_FALSE) {
			System.err.println("Failed to initialise GLFW!");
			return false;
		}

		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		ID = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
		if (ID == NULL) {
			System.err.println("Failed to create the window!");
			return false;
		}

		ByteBuffer vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(ID, (GLFWvidmode.width(vidmode) - WIDTH) / 2, (GLFWvidmode.height(vidmode) - HEIGHT) / 2);

		glfwMakeContextCurrent(ID);
		glfwShowWindow(ID);
		GLContext.createFromCurrent();
		GL.createCapabilities(true);

		//glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return true;
	}
	
	public void update() {
		glfwPollEvents();
		glfwSwapBuffers(ID);
	}
	
	public void clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	public long getID() {
		return ID;
	}

}
