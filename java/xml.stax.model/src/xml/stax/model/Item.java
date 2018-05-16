package xml.stax.model;

public class Item {
	private String date;
	private String mode;
	private String unit;
	private String current;
	private String interactive;
	public String getData() {
		return date;
	}
	public void setDate(String dates) {
		this.date = dates;
	}
	public String getMode() {
		return mode;
	}
	public void setMode(String modes) {
		this.mode = modes;
	}
	public String getUnit() {
		return unit;
	}
	public void setUnit(String unit) {
		this.unit = unit;
	}
	public String getCurrent() {
		return current;
	}
	public void setCurrent(String current) {
		this.current = current;
	}
	public String getInterative() {
		return interactive;
	}
	public void setInteractive( String interactive) {
		this.interactive = interactive;
	}
	@Override
	public String toString() {
		return "ITem [current=" + current+", date="+ date+" , interactive ="+ interactive+ " , mode="+ mode+ " , unit="+ unit +"J";
	}
}
