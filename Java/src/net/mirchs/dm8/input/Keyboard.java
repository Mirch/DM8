package net.mirchs.dm8.input;

import org.lwjgl.glfw.GLFWKeyCallback;
import static org.lwjgl.glfw.GLFW.*;

public class Keyboard extends GLFWKeyCallback {

	private static boolean[] keys = new boolean[65536];

	public void invoke(long window, int key, int scancode, int action, int mods) {
		keys[key] = (action != GLFW_RELEASE);

	}

	public static boolean isKeyDown(int keycode) {
		return keys[keycode];
	}

}
