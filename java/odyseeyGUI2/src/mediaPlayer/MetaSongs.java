package mediaPlayer;

import javafx.beans.property.SimpleStringProperty;

public class MetaSongs {

	public SimpleStringProperty songName = new SimpleStringProperty();
	String gender = "";
	public SimpleStringProperty Artist = new SimpleStringProperty();
	public SimpleStringProperty Album = new SimpleStringProperty();
	String year = "";
	String Lyrics = ""; 
	String Category = "";
	
	public MetaSongs(String songName, String gender, String artist, String album, String year, String lyrics,
			String category) {
		super();
		this.songName.setValue(songName);
		this.gender = gender;
		Artist.setValue(artist);
		Album.setValue(album);
		this.year = year;
		Lyrics = lyrics;
		Category = category;
	}
	
	
	
	//getters
	public String getSongName() {
		return songName.getValue();
	}
	public String getGender() {
		return gender;
	}
	public String getArtist() {
		return Artist.getValue();
	}
	public String getAlbum() {
		return Album.getValue();
	}
	public String getYear() {
		return year;
	}
	public String getLyrics() {
		return Lyrics;
	}
	public String getCategory() {
		return Category;
	}
	
	
	
	//Setters
	public void setGender(String gender) {
		this.gender = gender;
	}
	public void setArtist(String artist) {
		Artist.setValue(artist);
	}
	public void setAlbum(String album) {
		Album.set(album);
	}
	public void setYear(String year) {
		this.year = year;
	}
	public void setLyrics(String lyrics) {
		Lyrics = lyrics;
	}
	public void setCategory(String category) {
		Category = category;
	}
	
	
	
	
	
}
