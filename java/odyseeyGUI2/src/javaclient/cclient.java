package javaclient;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class cclient {

    private String ip;
    private int port;
    private String lastReponse;

    public cclient(String ip, int port) {
        this.ip = ip;
        this.port = port;
        this.lastReponse = "";
    }

    public void setConnection(String ip, int port) {
        this.ip = ip;
        this.port = port;
    }

    public String sendMessage(String message) {
        try {

            Socket clientSocket = new Socket(ip, port);

            DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
            BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));


            outToServer.write(message.getBytes());

            outToServer.flush();

            System.out.println("Message sent: " + message);

            String temp = inFromServer.readLine();

            while(temp != null) {
                lastReponse += temp;
                temp = inFromServer.readLine();
            }

            System.out.println("\n");
            System.out.println("Response: " + lastReponse);
            clientSocket.close();

            return lastReponse;
        } catch (Exception e){
            e.printStackTrace();
            return e.toString();
        }
    }

    public String getLastReponse() {
        return lastReponse;
    }

}
