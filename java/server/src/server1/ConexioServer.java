package server1;
import java.io.*;
import java.net.*;
public class ConexioServer {
final int Puerto = 8088;
ServerSocket sc;
Socket so;

DataOutputStream salida;
String mensajeRec;

public void initServer() {
	BufferedReader entrada;
	try {
		sc = new ServerSocket(Puerto);
		so = new Socket();
		System.out.println("esperando una conexion");
		so = sc.accept();
		System.out.println("Un cliente se ha conectado");
		entrada = new BufferedReader(new InputStreamReader(so.getInputStream()));
		salida = new DataOutputStream(so.getOutputStream());
		System.out.println("confirmando conexion");
		salida.writeUTF("Conexion exitosa");
		
		mensajeRec = entrada.readLine();
		System.out.println(mensajeRec);
		salida.writeUTF("se recibio el mejs");
		salida.writeUTF("Gracias por cone");
		System.out.println("cerrando conezion");
        sc.close();
        
	} catch (Exception e) {
		System.out.println("Error: "+e.getMessage());
		// TODO: handle exception
	}
}
}
