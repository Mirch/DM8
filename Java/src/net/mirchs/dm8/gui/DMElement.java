package net.mirchs.dm8.gui;

import net.mirchs.dm8.graphics.Shader;
import net.mirchs.dm8.graphics.Texture;
import net.mirchs.dm8.graphics.buffers.VertexArray;
import net.mirchs.dm8.math.Vector2f;

public class DMElement {

	protected Vector2f position;
	protected int width, height;

	protected Texture texture;
	protected VertexArray mesh;
	protected Shader shader = new Shader("shaders/element.vert", "shaders/element.frag");
	

	public void update() {

	}

	public void render() {

	}

	public void setPosition(Vector2f position) {
		this.position.x = position.x;
		this.position.y = position.y;
	}

}
