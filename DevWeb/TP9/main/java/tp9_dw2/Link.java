package tp9_dw2;

//*
public class Link {
	public final String href;
	public final String text;
	public Link(String href, String text) {
		super();
		this.href = href;
		this.text = text;
	}
	public String getHref() {
		return href;
	}
	public String getText() {
		return text;
	}
}

/*/
public record Link(String href, String text) { }
//*/