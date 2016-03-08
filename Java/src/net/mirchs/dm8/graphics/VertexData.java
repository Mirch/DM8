package net.mirchs.dm8.graphics;

import java.nio.ByteBuffer;

import net.mirchs.dm8.math.Vector2f;
import net.mirchs.dm8.math.Vector3f;
import net.mirchs.dm8.math.Vector4f;

public class VertexData {

	public ByteBuffer bytebuffer;

	public VertexData(ByteBuffer buffer) {
		this.bytebuffer = buffer;
	}

	public void addVertex(Vector3f position) {
		bytebuffer.putFloat(position.x);
		bytebuffer.putFloat(position.y);
		bytebuffer.putFloat(position.z);
	}


	public void addColor(int color) {
		bytebuffer.putInt(color);

	}

	public void addTextCoord(Vector2f coord) {
		bytebuffer.putFloat(coord.x);
		bytebuffer.putFloat(coord.y);
	}
	
	public void addTextCoord(float x, float y) {
		bytebuffer.putFloat(x);
		bytebuffer.putFloat(y);
	}
	
	public void addTID(float tid) {
		bytebuffer.putFloat(tid);
	}

}
