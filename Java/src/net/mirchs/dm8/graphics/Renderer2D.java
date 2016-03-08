package net.mirchs.dm8.graphics;

import java.util.ArrayList;
import java.util.List;

import net.mirchs.dm8.math.Matrix4f;

public abstract class Renderer2D {

	protected List<Matrix4f> transformationStack;
	protected Matrix4f transfBack;

	protected Renderer2D() {
		transformationStack = new ArrayList<>();
		transformationStack.add(Matrix4f.identity());
		transfBack = Matrix4f.identity();
	}

	public abstract void begin();

	public abstract void end();

	public abstract void submit(Renderable2D renderable);

	public abstract void flush();

	public void push(Matrix4f matrix, boolean override) {
		if (override)
			transformationStack.add(matrix);
		else
			transformationStack.add(transformationStack.get(transformationStack.size() - 1).multiply(matrix));
		
		transfBack = transformationStack.get(transformationStack.size() - 1);
	}

	public void pop() {
		if (transformationStack.size() > 1)
			transformationStack.remove(transformationStack.size() - 1);
	}

}
