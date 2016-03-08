package net.mirchs.dm8.graphics.buffers;

import static org.lwjgl.opengl.GL15.*;

import net.mirchs.dm8.utils.BufferUtils;

public class IndexBuffer {

	private int ID;
	private int count;

	public IndexBuffer(int[] data) {
		count = data.length;
		
		ID = glGenBuffers();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, BufferUtils.createIntBuffer(data), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}

	public void bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}

	public void unbind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	
	public int getCount() {
		return count;
	}
}
