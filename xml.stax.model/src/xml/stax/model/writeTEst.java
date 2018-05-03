package xml.stax.model;
import xml.stax.model.writer;

public class writeTEst {
	public static void main(String[] args) {
	writer config = new writer();
    try {
    	config.setFile("config2.xml");
        config.saveConfig();
    } catch (Exception e) {
        e.printStackTrace();
    }
	}
}
