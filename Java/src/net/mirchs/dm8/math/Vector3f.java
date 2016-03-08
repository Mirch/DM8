package net.mirchs.dm8.math;

public class Vector3f {

	public float x, y, z;

	public Vector3f() {
	}

	public Vector3f(float x, float y, float z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	public Vector3f add(Vector3f other) {
		this.x += other.x;
		this.y += other.y;
		this.z += other.z;

		return this;
	}

	public Vector3f subtract(Vector3f other) {
		this.x -= other.x;
		this.y -= other.y;
		this.z -= other.z;

		return this;
	}

	public Vector3f multiply(Vector3f other) {
		this.x *= other.x;
		this.y *= other.y;
		this.z *= other.z;

		return this;
	}

	public Vector3f divide(Vector3f other) {
		this.x /= other.x;
		this.y /= other.y;
		this.z /= other.z;

		return this;
	}

	public boolean equals(Vector3f other) {
		if (this.x != other.x || this.y != other.y || this.z != other.z) return false;
		return true;
	}

}
