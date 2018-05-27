package xml;
import java.util.List;


public class ReadTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		        StaXParser read = new StaXParser();
		        List<Item> readConfig = read.readConfig("../config2.xml");
		        for (Item item : readConfig) {
		            System.out.println(item);
		        }
		    }
		

	

}
