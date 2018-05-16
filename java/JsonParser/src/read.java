
public class read {

	public static void main(String[] args) {
		WriteJson testW = new WriteJson();
		testW.saveJson();
		readjson testR = new readjson();
		testR.read();
	}

}
