package net.mirchs.dm8.utils;

import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;

import javax.imageio.ImageIO;

public class FileUtils {
	private FileUtils() {
	}

	public static String loadAsString(String file) {
		StringBuilder result = new StringBuilder();
		try {
			BufferedReader reader = new BufferedReader(new FileReader(file));
			String buffer = "";
			while ((buffer = reader.readLine()) != null) {
				result.append(buffer + '\n');
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return result.toString();
	}

	public static void loadImage(String file, int[] pixels) {
		try {
			BufferedImage image = ImageIO.read(new FileInputStream(file));
			int width = image.getWidth();
			int height = image.getHeight();
			
			image.getRGB(0, 0, width, height, pixels, 0, width);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
