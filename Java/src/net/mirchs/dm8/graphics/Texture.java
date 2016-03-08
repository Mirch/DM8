package net.mirchs.dm8.graphics;

import static org.lwjgl.opengl.GL11.*;

import java.awt.image.BufferedImage;
import java.io.FileInputStream;
import java.io.IOException;

import javax.imageio.ImageIO;

import net.mirchs.dm8.utils.BufferUtils;
import net.mirchs.dm8.utils.FileUtils;

public class Texture {

	private int width, height;
	private int[] pixels;

	private int TID;

	private int color;

	public Texture(String path) {
		TID = load(path);
	}

	public Texture(int width, int height, int color) {
		this.width = width;
		this.height = height;
		TID = load(color);
	}

	private int load(String path) {
		try {
			BufferedImage image = ImageIO.read(new FileInputStream(path));
			width = image.getWidth();
			height = image.getHeight();
			pixels = new int[width * height];
			image.getRGB(0, 0, width, height, pixels, 0, width);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return createTexture();
	}

	private int load(int color) {
		pixels = new int[width * height];

		for (int i = 0; i < pixels.length; i++)
			pixels[i] = color;

		return createTexture();
	}

	private int createTexture() {
		int[] data = new int[width * height];

		for (int i = 0; i < pixels.length; i++) {
			int a = (pixels[i] & 0xff000000) >> 24;
			int r = (pixels[i] & 0xff0000) >> 16;
			int g = (pixels[i] & 0xff00) >> 8;
			int b = (pixels[i] & 0xff);

			data[i] = a << 24 | b << 16 | g << 8 | r;
		}

		int result = glGenTextures();
		glBindTexture(GL_TEXTURE_2D, result);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, BufferUtils.createIntBuffer(data));
		glBindTexture(GL_TEXTURE_2D, 0);
		return result;

	}

	public void bind() {
		glBindTexture(GL_TEXTURE_2D, TID);
	}

	public void unbind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	public int getWidth() {
		return width;
	}

	public int getHeight() {
		return height;
	}

	public int getID() {
		return TID;
	}

}
