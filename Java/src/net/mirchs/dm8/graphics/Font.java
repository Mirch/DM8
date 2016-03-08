package net.mirchs.dm8.graphics;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class Font {

	public static String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	private int size = 64;

	private String path;
	private int[] pixels;
	private int width, height;

	public Font(String path) {
		this.path = path;
		
	}

}
