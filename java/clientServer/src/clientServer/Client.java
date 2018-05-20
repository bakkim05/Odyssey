package clientServer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.*;

public class Client {
	final String Host = "localhost";
	 final int Puerto = 8085;
	 Socket SocketClient;
	 BufferedReader entradi,teclado;
	 PrintStream salida;
	 
	 public void initClient() {
		 try {
			SocketClient = new Socket(Host, Puerto);
			entradi = new BufferedReader(new InputStreamReader(SocketClient.getInputStream()));
			teclado = new BufferedReader(new InputStreamReader(System.in));
			String tec = teclado.readLine();
			salida = new PrintStream(SocketClient.getOutputStream());
			salida.println(tec);
			String mag = entradi.readLine();
			System.out.println(mag);
			entradi.close();
			salida.close();
			teclado.close();
			SocketClient.close();
		 } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("Error: "+ e.getMessage());
		}
		 
	 }
}
