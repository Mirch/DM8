package net.mirchs.dm8.input;

import org.lwjgl.glfw.GLFWMouseButtonCallback;
import static org.lwjgl.glfw.GLFW.*;

public class Mouse extends GLFWMouseButtonCallback {
	
	public static boolean[] buttons = new boolean[64];

	@Override
	public void invoke(long window, int button, int action, int mods) {
		buttons[button] = (action != GLFW_RELEASE);
	}
	
	public static boolean isButtonDown(int button) {
		return buttons[button];
	}

}
