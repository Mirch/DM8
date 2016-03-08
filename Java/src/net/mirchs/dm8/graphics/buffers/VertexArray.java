package net.mirchs.dm8.graphics.buffers;

import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL15.*;
import static org.lwjgl.opengl.GL20.*;
import static org.lwjgl.opengl.GL30.*;

import java.util.ArrayList;
import java.util.List;

public class VertexArray {

	private int ID;
	private List<Buffer> buffers = new ArrayList<Buffer>();

	public VertexArray() {
		ID = glGenVertexArrays();
	}	
	
	public void addBuffer(Buffer buffer, int index) {
		bind();
		buffer.bind();
		
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer.getComponentCount(), GL_FLOAT, false, 0, 0);
		
		buffer.unbind();
		unbind();
		
		buffers.add(buffer);
	}

	public void bind() {
		glBindVertexArray(ID);
	}

	public void unbind() {
		glBindVertexArray(0);
	}


}
