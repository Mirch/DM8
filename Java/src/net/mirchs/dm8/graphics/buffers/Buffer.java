package net.mirchs.dm8.graphics.buffers;

import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL15.*;
import static org.lwjgl.opengl.GL20.*;
import static org.lwjgl.opengl.GL30.*;

import net.mirchs.dm8.utils.BufferUtils;

public class Buffer {

	private int ID;
	private int componentCount;
	

	public Buffer(float[] data, int componentCount) {
		this.componentCount = componentCount;

		ID = glGenBuffers();
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, BufferUtils.createFloatBuffer(data), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

	public void bind() {
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	public void unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	public int getComponentCount() {
		return componentCount;
	}

}
