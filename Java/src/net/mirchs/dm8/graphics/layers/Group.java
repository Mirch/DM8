package net.mirchs.dm8.graphics.layers;

import java.util.ArrayList;
import java.util.List;

import net.mirchs.dm8.graphics.Renderable2D;
import net.mirchs.dm8.graphics.Renderer2D;
import net.mirchs.dm8.math.Matrix4f;

public class Group extends Renderable2D {

	private List<Renderable2D> renderables;
	private Matrix4f transformationMatrix;
	
	public Group(Matrix4f transform) {
		renderables = new ArrayList<Renderable2D>();
		this.transformationMatrix = transform;
	}
	
	public void add(Renderable2D renderable) {
		renderables.add(renderable);
	}

	public void submit(Renderer2D renderer) {
		renderer.push(transformationMatrix, false);
		for (Renderable2D renderable : renderables) {
			renderable.submit(renderer);
		}
		renderer.pop();
	}

}
