package net.mirchs.dm8.math;

import java.nio.FloatBuffer;

import net.mirchs.dm8.utils.BufferUtils;

public class Matrix4f {

	public final static int SIZE = 4 * 4;
	public float[] elements = new float[SIZE];

	public Matrix4f() {
	}

	public static Matrix4f identity() {
		Matrix4f result = new Matrix4f();

		result.elements[0 + 0 * 4] = 1.0f;
		result.elements[1 + 1 * 4] = 1.0f;
		result.elements[2 + 2 * 4] = 1.0f;
		result.elements[3 + 3 * 4] = 1.0f;

		return result;
	}

	public static Matrix4f ortho(float left, float right, float bottom, float top, float near, float far) {
		Matrix4f result = identity();

		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);

		return result;
	}

	public static Matrix4f rotate(float angle) {
		Matrix4f result = identity();
		float r = (float) Math.toRadians(angle);
		float cos = (float) Math.cos(r);
		float sin = (float) Math.sin(r);

		result.elements[0 + 0 * 4] = cos;
		result.elements[1 + 0 * 4] = sin;
		result.elements[0 + 1 * 4] = -sin;
		result.elements[1 + 1 * 4] = cos;

		return result;
	}

	public static Matrix4f translate(Vector3f vector) {
		Matrix4f result = identity();
		result.elements[0 + 3 * 4] = vector.x;
		result.elements[1 + 3 * 4] = vector.y;
		result.elements[2 + 3 * 4] = vector.z;

		return result;
	}

	public Matrix4f multiply(Matrix4f other) {
		Matrix4f result = new Matrix4f();

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				float sum = 0.0f;
				for (int e = 0; e < 4; e++) {
					sum += this.elements[x + e * 4] * other.elements[e + y * 4];
				}
				result.elements[x + y * 4] = sum;
			}
		}
		return result;
	}

	public Vector3f multiply(Vector3f other) {
		return new Vector3f(
				elements[0] * other.x + elements[4] * other.y + elements[8] * other.z + elements[12],
				elements[1] * other.x + elements[5] * other.y + elements[9] * other.z + elements[13],
				elements[2] * other.x + elements[6] * other.y + elements[10] * other.z + elements[14]
		);
	}

	public Vector4f multiply(Vector4f other) {
		return new Vector4f(
				elements[0] * other.x + elements[4] * other.y + elements[8] * other.z + elements[12] * other.w,
				elements[1] * other.x + elements[5] * other.y + elements[9] * other.z + elements[13] * other.w,
				elements[2] * other.x + elements[6] * other.y + elements[10] * other.z + elements[14] * other.w,
				elements[3] * other.x + elements[7] * other.y + elements[11] * other.z + elements[15] * other.w
		);
	}

	public FloatBuffer toFloatBuffer() {
		return BufferUtils.createFloatBuffer(elements);
	}

}
