package serverClient;
import java.net.*;
import java.io.*;

public class client {
 final String Host = "localhost";
 final int Puerto = 8088;
 Socket sc;
 DataOutputStream mensaje;
 DataInputStream entrada;
 
 public void initClient() {
	 try {
		mensaje = new DataOutputStream(sc.getOutputStream());
		mensaje.writeUTF("Hola que tal");
		sc.close();
	 } catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		System.out.println("Error: "+ e.getMessage());
	}
	 
 }
}
