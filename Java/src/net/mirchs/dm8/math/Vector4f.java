package net.mirchs.dm8.math;

public class Vector4f {

	public float x, y, z, w;

	public Vector4f() {
	}

	public Vector4f(float x, float y, float z, float w) {
		this.x = x;
		this.y = y;
		this.z = z;
		this.w = w;
	}

	public void add(Vector4f other) {
		this.x += other.x;
		this.y += other.y;
		this.z += other.z;
		this.w += other.w;
	}

	public void subtract(Vector4f other) {
		this.x -= other.x;
		this.y -= other.y;
		this.z -= other.z;
		this.w -= other.w;
	}

	public void multiply(Vector4f other) {
		this.x *= other.x;
		this.y *= other.y;
		this.z *= other.z;
		this.w *= other.w;
	}

	public void divide(Vector4f other) {
		this.x /= other.x;
		this.y /= other.y;
		this.z /= other.z;
		this.w /= other.w;
	}

	public boolean equals(Vector4f other) {
		if (this.x != other.x || this.y != other.y || this.z != other.z || this.w != other.w) return false;
		return true;
	}

}
