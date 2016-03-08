package net.mirchs.dm8.graphics;

import static org.lwjgl.opengl.GL20.*;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.util.HashMap;
import java.util.Map;

import net.mirchs.dm8.math.Matrix4f;
import net.mirchs.dm8.math.Vector3f;
import net.mirchs.dm8.utils.BufferUtils;
import net.mirchs.dm8.utils.ShaderUtils;

public class Shader {


	private boolean enabled = false;

	private final int ID;
	private Map<String, Integer> locationCache = new HashMap<String, Integer>();

	public Shader(String vertex, String fragment) {
		ID = ShaderUtils.load(vertex, fragment);
	}

	public int getUniform(String name) {
		if (locationCache.containsKey(name)) return locationCache.get(name);

		int result = glGetUniformLocation(ID, name);

		if (result == -1)
			System.err.println("Could not find uniform variable: " + name);
		else
			locationCache.put(name, result);
		return result;
	}

	public void setUniform1i(String name, int value) {
		glUniform1i(getUniform(name), value);
	}
	
	public void setUniform1iv(String name , int[] values) {
		IntBuffer fb = BufferUtils.createIntBuffer(values);
		glUniform1iv(getUniform(name), fb);
	}


	public void setUniform1f(String name, float value) {
		glUniform1f(getUniform(name), value);
	}
	
	public void setUniform1fv(String name , float[] values) {
		FloatBuffer fb = BufferUtils.createFloatBuffer(values);
		glUniform1fv(getUniform(name), fb);
	}


	public void setUniform2f(String name, float x, float y) {
		glUniform2f(getUniform(name), x, y);
	}

	public void setUniform3f(String name, Vector3f vector) {
		glUniform3f(getUniform(name), vector.x, vector.y, vector.z);
	}

	public void setUniformMat4f(String name, Matrix4f matrix) {
		glUniformMatrix4fv(getUniform(name), false, matrix.toFloatBuffer());
	}

	public void enable() {
		glUseProgram(ID);
		enabled = true;
	}

	public void disable() {
		glUseProgram(0);
		enabled = false;
	}

}
