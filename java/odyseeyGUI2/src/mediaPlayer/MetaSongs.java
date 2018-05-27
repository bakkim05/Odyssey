package mediaPlayer;

public class MetaSongs {

	String songName = "";
	String gender = "";
	String Artist = "";
	String Album = "";
	String year = "";
	String Lyrics = ""; 
	String Category = "";
	
	public MetaSongs(String songName, String gender, String artist, String album, String year, String lyrics,
			String category) {
		super();
		this.songName = songName;
		this.gender = gender;
		Artist = artist;
		Album = album;
		this.year = year;
		Lyrics = lyrics;
		Category = category;
	}
	
	
	
	//getters
	public String getSongName() {
		return songName;
	}
	public String getGender() {
		return gender;
	}
	public String getArtist() {
		return Artist;
	}
	public String getAlbum() {
		return Album;
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
		Artist = artist;
	}
	public void setAlbum(String album) {
		Album = album;
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
