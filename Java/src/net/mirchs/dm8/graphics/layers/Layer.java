package net.mirchs.dm8.graphics.layers;

import java.util.ArrayList;

import net.mirchs.dm8.graphics.Renderable2D;
import net.mirchs.dm8.graphics.Renderer2D;
import net.mirchs.dm8.graphics.Shader;
import net.mirchs.dm8.math.Matrix4f;
import net.mirchs.dm8.math.Vector3f;

public abstract class Layer {

	protected Renderer2D renderer;
	protected ArrayList<Renderable2D> renderables;
	protected Shader shader;
	protected Matrix4f pr_matrix;

	protected Layer(Renderer2D renderer, Shader shader, Matrix4f projectionMatrix) {
		this.renderer = renderer;
		this.shader = shader;
		this.pr_matrix = projectionMatrix;
		renderables = new ArrayList<>();

		shader.enable();
		shader.setUniformMat4f("pr_matrix", pr_matrix);
		shader.disable();

	}

	public Layer() {

		shader.enable();
		shader.setUniformMat4f("pr_matrix", pr_matrix);
		shader.disable();
	}

	public void add(Renderable2D renderable) {
		renderables.add(renderable);
	}

	public void render() {
		shader.enable();
		renderer.begin();
		for (Renderable2D renderable : renderables) {
			renderable.submit(renderer);
		}
		renderer.pop();
		renderer.end();
		renderer.flush();
		shader.disable();
	}

}
