package net.mirchs.dm8.graphics;

import net.mirchs.dm8.graphics.buffers.Buffer;
import net.mirchs.dm8.graphics.buffers.IndexBuffer;
import net.mirchs.dm8.graphics.buffers.VertexArray;
import net.mirchs.dm8.math.Matrix4f;
import net.mirchs.dm8.math.Vector2f;
import net.mirchs.dm8.math.Vector3f;
import net.mirchs.dm8.math.Vector4f;

public class Sprite extends Renderable2D {

	public Sprite(Vector3f position, Vector2f size, Texture texture) {
		super(position, size, texture);
		this.position = position;
		this.size = size;
		this.texture = texture;
		this.color = new Vector4f(1, 0, 1, 1);
	}

	public Sprite(Vector3f position, Vector2f size, Vector4f color) {
		super(position, size, color);
		this.position = position;
		this.size = size;
		this.color = color;

	}

	public Vector3f getPosition() {
		return position;
	}

	public Vector2f getSize() {
		return size;
	}

	public Vector4f getColor() {
		return color;
	}

	public Texture getTexture() {
		return texture;
	}

	public boolean isTextured() {
		return (texture == null) ? false : true;
	}

}
