package net.mirchs.dm8.graphics.layers;

import net.mirchs.dm8.graphics.DMRenderer2D;
import net.mirchs.dm8.graphics.Renderer2D;
import net.mirchs.dm8.graphics.Shader;
import net.mirchs.dm8.math.Matrix4f;

public class Layer2D extends Layer {

	public Layer2D(Shader shader) {
		super(new DMRenderer2D(), shader, Matrix4f.ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f));
	}

}
