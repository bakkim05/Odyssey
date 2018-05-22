package javaclient;

import java.io.*;
import java.net.*;
import java.util.List;

import xml.Item;
import xml.StaXParser;

/**
 * @author Eric Bruno
 */
public class SocketClient {
    private Listener listener = null;
    private Sender sender = null;
    public boolean connected = false;
    ServerResponses viewer = null;

    class Listener extends Thread {
        Socket conn = null;
        boolean listening = true;

        public Listener(Socket conn) {
            this.conn = conn;
            this.setName("JavaClientSocketListener");
            this.start();
        }

        @Override public void run() {

            InputStream instream = null;

            try {
                BufferedReader reader =
                    new BufferedReader(new InputStreamReader(conn.getInputStream()));


                while ( listening ) {
                    String xml = reader.readLine();
                    if ( xml == null ) {
                        // Connection lost
                        return;
                    }

                    System.out.println("XML: " + xml + "\n\n");

                    // Hand off to the UI
                    if ( xml.indexOf("HostnameResponse") != -1 )
                        viewer.onHostnameResponse(xml);
                    else if ( xml.indexOf("MemoryResponse") != -1 )
                        viewer.onMemoryResponse(xml);
                    else if ( xml.indexOf("RandomNumberResponse") != -1 )
                        viewer.onRandomNumberResponse(xml);
                }
            }
            catch ( StreamCorruptedException sce) {
                // skip over the bad bytes
                try {
                    if ( instream != null )
                        instream.skip(instream.available());
                }
                catch ( Exception e1 ) {
                    listening = false;
                }
            }
            catch ( Exception e ) {
                e.printStackTrace();
                listening = false;
            }
        }
    }

    class Sender {
    	
        static final String DatosCancion = "<Data><Music nombre=\"Havana\"><Gender>pop</Gender><Artist>Camila Cabello</Artist><Album>Camila</Album><Year>2018</Year><Category>latin pop</Category><Lyrics>SERW</Lyrics></Music><apCode>0</apCode></Data>";
        static final String InfoUser = "<InfoUser><Username username=\"Faridd\"><Name>Farid Marin</Name><Age>19</Age><FavSongs>Camila Cabello, howlong</FavSongs><password>12345</password><Friends>jung, kim</Friends></Username><apCode>0</apCode></InfoUser>";
        static final String RANDOM_NUM = "<Request><Name>GetRandomNumber</Name></Request>";
        
        Socket conn;
        BufferedOutputStream os = null;

        public Sender(Socket conn) {
        	
            try {
                this.conn = conn;
                this.conn.setTcpNoDelay(true);
                this.os = new BufferedOutputStream( conn.getOutputStream() );
            }
            catch ( Exception e ) {
                e.printStackTrace();
            }
        }

        public void requestHostname() {
            serializeAndSendMessage(DatosCancion);
        }

        public void requestMemory() {
            serializeAndSendMessage(InfoUser);
        }

        public void requestRandomNumber() {
            serializeAndSendMessage(RANDOM_NUM);
        }

        private void serializeAndSendMessage(String msg) {
            try {
                os.write( msg.getBytes() );
                os.flush();
            }
            catch ( Exception e ) {
                e.printStackTrace();
            }
        }
    }

    public SocketClient(String IPAddress, ServerResponses viewer) {
        try {
            // Connect to the server at the given address on port 8080
            if ( IPAddress == null || IPAddress.length() == 0 )
                IPAddress = "localhost";
            Socket conn = new Socket( IPAddress, 8085 );
            conn.setTcpNoDelay(true);
            this.listener = new Listener(conn);
            this.sender = new Sender(conn);
            this.connected = true;
            this.viewer = viewer;
        }
        catch ( Exception e ) {
            connected = false;
            e.printStackTrace();
        }
    }

    public boolean isConnected() {
        return connected;
    }

    public void requestHostname() {
        sender.requestHostname();
    }

    public void requestMemory() {
        sender.requestMemory();
    }

    public void requestRandomNumber() {
        sender.requestRandomNumber();
    }
}
