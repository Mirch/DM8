package net.mirchs.dm8.gui;

import java.util.ArrayList;
import java.util.List;

import net.mirchs.dm8.graphics.Shader;
import net.mirchs.dm8.graphics.Texture;
import net.mirchs.dm8.graphics.buffers.VertexArray;
import net.mirchs.dm8.math.Matrix4f;
import net.mirchs.dm8.math.Vector3f;

public class DMPanel {

	private int startX, startY;
	private int width, height;

	private Texture texture;
	private VertexArray mesh;
	private Shader shader;
	
	private List<DMElement> elements = new ArrayList<DMElement>();

	public DMPanel(int startX, int startY, int width, int height, Texture texture) {
		this.startX = startX;
		this.startY = startY;
		this.width = width;
		this.height = height;
		this.texture = texture;

		shader = new Shader("shaders/element.vert", "shaders/element.frag");

		float[] vertices = new float[] {
				0.0f, 0.0f, 0.2f,
				0.0f, height, 0.2f,
				width, height, 0.2f,
				width, 0.0f, 0.2f
		};

		byte[] indices = new byte[] {
				0, 1, 2,
				2, 3, 0
		};

		float[] tcs = new float[] {
				0, 1,
				0, 0,
				1, 0,
				1, 1
		};

		//mesh = new VertexArray(vertices, indices, tcs);

	}

	public DMPanel(int startX, int startY, int width, int height, int color) {
		this(startX, startY, width, height, new Texture(width, height, color));
	}
	
	public void add(DMElement element) {
		elements.add(element);
	}

	public void render() {
		texture.bind();
		shader.enable();
		shader.setUniformMat4f("ml_matrix", Matrix4f.translate(new Vector3f(startX, startY, 0.0f)));
	//	mesh.render();
		shader.disable();
		texture.unbind();
	}

	public void update() {

	}
	
	public Shader getShader() {
		return shader;
	}

}
