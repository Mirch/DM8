package net.mirchs.dm8.math;

public class Vector2f {

	public float x, y;

	public Vector2f() {
	}

	public Vector2f(float x, float y) {
		this.x = x;
		this.y = y;
	}

	public Vector2f add(Vector2f other) {
		this.x += other.x;
		this.y += other.y;

		return this;
	}

	public Vector2f subtract(Vector2f other) {
		this.x -= other.x;
		this.y -= other.y;

		return this;
	}

	public Vector2f multiply(Vector2f other) {
		this.x *= other.x;
		this.y *= other.y;

		return this;
	}

	public Vector2f divide(Vector2f other) {
		this.x /= other.x;
		this.y /= other.y;

		return this;
	}

	public boolean equals(Vector2f other) {
		if (this.x != other.x || this.y != other.y) return false;
		return true;
	}

}
