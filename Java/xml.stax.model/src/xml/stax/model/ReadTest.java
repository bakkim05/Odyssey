package xml.stax.model;
import java.util.List;

import xml.stax.model.StaXParser;
import xml.stax.model.Item;
public class ReadTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		        StaXParser read = new StaXParser();
		        List<Item> readConfig = read.readConfig("config2.xml");
		        for (Item item : readConfig) {
		            System.out.println(item);
		        }
		    }
		

	

}
