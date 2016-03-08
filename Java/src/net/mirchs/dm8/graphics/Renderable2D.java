package net.mirchs.dm8.graphics;

import java.util.ArrayList;
import java.util.List;

import net.mirchs.dm8.math.Vector2f;
import net.mirchs.dm8.math.Vector3f;
import net.mirchs.dm8.math.Vector4f;

public class Renderable2D {

	protected Vector2f size;
	protected Vector3f position;
	protected Vector4f color;
	protected Texture texture;
	protected List<Vector2f> UV = new ArrayList<Vector2f>();

	protected Renderable2D() {

	}

	public Renderable2D(Vector3f position, Vector2f size, Texture texture) {
		setUVDefaults();
	}

	public Renderable2D(Vector3f position, Vector2f size, Vector4f color) {
		setUVDefaults();
	}

	private void setUVDefaults() {
		UV.add(new Vector2f(0, 1));
		UV.add(new Vector2f(0, 0));
		UV.add(new Vector2f(1, 0));
		UV.add(new Vector2f(1, 1));
	}

	public List<Vector2f> getUV() {
		return UV;
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
	
	public int getTID() {
		return (texture == null) ? 0 : (texture.getID());
	}

	public void submit(Renderer2D renderer) {
		renderer.submit(this);
	}

}
