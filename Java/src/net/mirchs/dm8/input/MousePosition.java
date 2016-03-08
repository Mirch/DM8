package net.mirchs.dm8.input;

import org.lwjgl.glfw.GLFWCursorPosCallback;

public class MousePosition extends GLFWCursorPosCallback {

	private static double xpos, ypos;
	
	public void invoke(long window, double xpos, double ypos) {
		this.xpos = xpos;
		this.ypos = ypos;
	}
	
	public static double getX() {
		return xpos;
	}
	
	public static double getY() {
		return ypos;
	}

}
