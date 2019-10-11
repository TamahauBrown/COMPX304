import java.io.*;
import java.net.*;
import java.security.*;
import sun.misc.BASE64Decoder;
import sun.misc.BASE64Encoder;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;

public class SimpleServer
{
	PublicKey k;
	KeyAgreement kAgreement;
	byte [] secret;

	public static void main(String [] args) throws Exception
	{
        System.out.println("Waiting for client to connect");
		SimpleServer server = new SimpleServer();
        ServerSocket socket = new ServerSocket(1234);
		Socket sock = socket.accept();
		InputStreamReader IR = new InputStreamReader(sock.getInputStream());
		BufferedReader BR = new BufferedReader(IR);
		
		String MESSAGE = BR.readLine();
		System.out.println(MESSAGE);
		
		if(MESSAGE != null)
		{
			PrintStream PS = new PrintStream(sock.getOutputStream());
            		String address = "10.2.0.2";
            
            try
            {
                InetAddress IP = InetAddress.getByName(address);
                PS.println("Hello " + "10.2.0.2");
                PS.println("Your IP address is " + IP.getHostAddress());
            }
            catch(UnknownHostException e)
            {
                System.err.println(address + " unknown host");
            }
		}
	}

	public void keyExchange() {
		KeyPairGenerator kp = null;
		try 
		{
			kp = KeyPairGenerator.getInstance("GC");
			kp.initialize(256);
			k = kp.getPublic();
			kAgreement = KeyAgreement.getInstance("GCDH");
			kAgrement.init(k.getPrivate());
		}
		catch(Exception e) 
		{
			// print stack trace 
            		e.printStackTrace();
		}
	}

	public void 
}
