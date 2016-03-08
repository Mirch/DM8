package net.mirchs.dm8.graphics;

import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.opengl.GL13.*;
import static org.lwjgl.opengl.GL15.*;
import static org.lwjgl.opengl.GL20.*;
import static org.lwjgl.opengl.GL30.*;

import java.util.ArrayList;
import java.util.List;

import net.mirchs.dm8.graphics.buffers.IndexBuffer;
import net.mirchs.dm8.math.Vector2f;
import net.mirchs.dm8.math.Vector3f;
import net.mirchs.dm8.math.Vector4f;

public class DMRenderer2D extends Renderer2D {

	private final long MAX_SPRITES = 60000;
	private final long VERTEX_SIZE = 28;
	private final long SPRITE_SIZE = VERTEX_SIZE * 4;
	private final long BUFFER_SIZE = SPRITE_SIZE * MAX_SPRITES;
	private final long INDICES_SIZE = MAX_SPRITES * 6;

	private final long SHADER_VERTEX_INDEX = 0;
	private final long SHADER_UV_INDEX = 1;
	private final long SHADER_TID_INDEX = 2;
	private final long SHADER_COLOR_INDEX = 3;

	private int vao;
	private IndexBuffer ibo;
	private int indexCount;
	private int vbo;
	private VertexData buffer;

	private List<Integer> textureSlots = new ArrayList<Integer>();

	public DMRenderer2D() {
		super();
		init();
	}

	private void init() {
		vao = glGenVertexArrays();
		vbo = glGenBuffers();

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, null, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray((int) SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray((int) SHADER_UV_INDEX);
		glEnableVertexAttribArray((int) SHADER_TID_INDEX);
		glEnableVertexAttribArray((int) SHADER_COLOR_INDEX);

		glVertexAttribPointer((int) SHADER_VERTEX_INDEX, 3, GL_FLOAT, false, (int) VERTEX_SIZE, 0);
		glVertexAttribPointer((int) SHADER_UV_INDEX, 2, GL_FLOAT, false, (int) VERTEX_SIZE, 3 * 4);
		glVertexAttribPointer((int) SHADER_TID_INDEX, 1, GL_FLOAT, false, (int) VERTEX_SIZE, 5 * 4);
		glVertexAttribPointer((int) SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, true, (int) VERTEX_SIZE, 6 * 4);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		int indices[] = new int[(int) INDICES_SIZE];

		int offset = 0;
		for (int i = 0; i < indices.length; i += 6) {
			indices[i] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		ibo = new IndexBuffer(indices);

		glBindVertexArray(0);

	}

	public void begin() {
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		buffer = new VertexData(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	}

	public void submit(Renderable2D sprite) {

		Vector3f position = sprite.getPosition();
		Vector2f size = sprite.getSize();
		Vector4f color = sprite.getColor();
		List<Vector2f> uv = sprite.getUV();
		int tid = sprite.getTID();

		int c = 0;
		float ts = 0.0f;

		if (tid > 0) {	
			boolean found = false;
			for (int i = 0; i < textureSlots.size(); i++) {
				if (textureSlots.get(i) == tid) {
					found = true;
					ts = (float) i + 1;
					break;
				}
			}

			if (!found) {
				if (textureSlots.size() >= 32) {
					end();
					flush();
					begin();
				}
				textureSlots.add(tid);
				ts = (float) (textureSlots.size());
			}

		} else {
			int r = (int) (color.x * 255.0f);
			int g = (int) (color.y * 255.0f);
			int b = (int) (color.z * 255.0f);
			int a = (int) (color.w * 255.0f);

			c = (a << 24) | (b << 16) | (g << 8) | r;

		}

		// VERTEX 1
		buffer.addVertex(transfBack.multiply(position));
		buffer.addTextCoord(uv.get(0));
		buffer.addTID(ts);
		buffer.addColor(c);

		// VERTEX 2
		buffer.addVertex(transfBack.multiply(new Vector3f(position.x, position.y + size.y, position.z)));
		buffer.addTextCoord(uv.get(1));
		buffer.addTID(ts);
		buffer.addColor(c);

		// VERTEX 3
		buffer.addVertex(transfBack.multiply(new Vector3f(position.x + size.x, position.y + size.y, position.z)));
		buffer.addTextCoord(uv.get(2));
		buffer.addTID(ts);
		buffer.addColor(c);

		// VERTEX 4
		buffer.addVertex(transfBack.multiply(new Vector3f(position.x + size.x, position.y, position.z)));
		buffer.addTextCoord(uv.get(3));
		buffer.addTID(ts);
		buffer.addColor(c);

		indexCount += 6;
	}

	public void end() {
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	public void flush() {
		for (int i = 0; i < textureSlots.size(); i++) {
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, textureSlots.get(i));
		}
		glBindVertexArray(vao);
		ibo.bind();

		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

		ibo.unbind();
		glBindVertexArray(0);

		indexCount = 0;
	}

}
