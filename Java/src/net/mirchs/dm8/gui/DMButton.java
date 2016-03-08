package net.mirchs.dm8.gui;

import net.mirchs.dm8.graphics.Texture;
import net.mirchs.dm8.math.Vector2f;

public class DMButton extends DMElement {
	
	private Texture hover_texture;
	private Texture click_texture;
	
	public DMButton(Texture normal, Texture hover, Texture click) {
		this.texture = normal;
		this.hover_texture = hover;
		this.click_texture = click;
	}

	
	public void setText(String text) {
		
	}
	

}
