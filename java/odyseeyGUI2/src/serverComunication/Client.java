package serverComunication;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {

	public static void main(String[] args)throws Exception {
		
		Client client = new Client();
		client.run();
		
	}

	private void run() throws UnknownHostException, IOException {

		Socket SOCK = new Socket("localhost",444);
		PrintStream ps = new PrintStream(SOCK.getOutputStream());
		ps.println("Hello from server to client");
		
		InputStreamReader ir = new InputStreamReader(SOCK.getInputStream()); 
		BufferedReader br = new BufferedReader(ir);
		
		String MESSAGE = br.readLine();
		System.out.println(MESSAGE);
		
		SOCK.close();
				
	}

}
