package xml;


public class writeTEst {
	public static void main(String[] args) {
	writer config = new writer();
    try {
    	config.setFile("config2.xml");
        config.saveConfig("Havana", "pop", "Camila Cabello", "Camila", "2018", "SERW", "latin pop", 000);
       
    } catch (Exception e) {
        e.printStackTrace();
    }
	}
}
