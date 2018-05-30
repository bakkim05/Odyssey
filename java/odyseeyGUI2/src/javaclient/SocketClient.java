package javaclient;

import java.io.*;
import java.net.*;
import java.util.List;


/**
 * @author Eric Bruno
 */
public class SocketClient {
    private Listener listener = null;
    private Sender sender = null;
    public boolean connected = false;
    public String message;
    public String concatenacion = "";
    public void concant(String value) {
    	System.out.println("contact"+value);
    	if(value != null) {
    		this.message += value;
    		System.out.println("valor final: "+this.message);
    	}else {
    		System.out.println("prueba");
    	}
    }
    class Listener extends Thread {
        Socket conn = null;
        boolean listening = true;
        public String perdida;

        public Listener(Socket conn) {
            this.conn = conn;
            this.setName("JavaClientSocketListener");
            this.start();
        }

        @Override public void run() {

            InputStream instream = null;

            try {
                InputStreamReader in = new InputStreamReader(conn.getInputStream());
                BufferedReader bre = new BufferedReader(in);
                String reply = "";
                System.out.println("hola ");
                for(int i =0; i<9; i++) {
                	System.out.println("se despicho");
                	System.out.println(bre.readLine());
                	reply += bre.readLine();
                	
                }
                conn.shutdownOutput();
                System.out.println("mesage: "+reply);
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
//clase sender
    class Sender {

        static final String DatosCancion = "<Data><Music nombre=\"dfgdf\"><Gender>pop</Gender><Artist>Camila Ca</Artist><Album>Camila</Album><Year>2018</Year><Category>latin pop</Category><Lyrics>dsfsdfds</Lyrics></Music><apCode>4</apCode></Data>";
        static final String InfoUser = "<InfoUser><Username username=\"Faridd\"><Name>Farid Marin</Name><Age>19</Age><FavSongs>Camila Cabello, howlong</FavSongs><password>12345</password><Friends>jung, kim</Friends></Username><apCode>4</apCode></InfoUser>";
        static final String Streaming = "Streaming";

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

        public void RequestMetadata(String file) {
        	String cadena;
    		StringBuilder duf = new StringBuilder();
    		FileReader f = null;
			try {
				f = new FileReader(file);
				BufferedReader b = new BufferedReader(f);
				while((cadena = b.readLine())!= null) {
					//System.out.println(cadena);
					duf.append(cadena);
				}
					//System.out.println(duf);
		    		b.close();

			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
            serializeAndSendMessage(DatosCancion);
        }

        public void InfoUser(String file) {
        	String cadena;
    		StringBuilder duf = new StringBuilder();
    		FileReader f = null;
			try {
				f = new FileReader(file);
				BufferedReader b = new BufferedReader(f);
				while((cadena = b.readLine())!= null) {
					System.out.println(cadena);
					duf.append(cadena);
				}
					System.out.println(duf);
		    		b.close();

			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
            serializeAndSendMessage(duf.toString());
        }

        public void requestRandomNumber() {
            serializeAndSendMessage(Streaming);
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
        private void deserializeAndGetMs() {
        	try {

        	}catch(Exception e) {
        		e.printStackTrace();
        	}
        }
    }

    public SocketClient(String IPAddress) {
        try {
            // Connect to the server at the given address on port 8080
            if ( IPAddress == null || IPAddress.length() == 0 )
                IPAddress = "localhost";
            Socket conn = new Socket( IPAddress, 8085 );
            conn.setTcpNoDelay(true);
            this.listener = new Listener(conn);
            this.sender = new Sender(conn);
            this.connected = true;
            //this.viewer = viewer;
        }
        catch ( Exception e ) {
            connected = false;
            e.printStackTrace();
        }
    }

    public boolean isConnected() {
        return connected;
    }

    public void sendMusic() {
    	String file = "config2.xml";
        sender.RequestMetadata(file);
    }

    public void SendUser() {
    	String file = "config1.xml";
        sender.InfoUser(file);
    }

    public void requestRandomNumber() {
        sender.requestRandomNumber();
    }
}
