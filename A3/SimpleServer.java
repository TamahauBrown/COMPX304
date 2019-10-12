import java.io.*;
import java.net.*;
import java.security.*;
import javax.crypto.*;

public class SimpleServer
{
	public static void main(String [] args) throws Exception
	{
		String key = args[0];
        System.out.println("Waiting for client to connect");
		SimpleServer server = new SimpleServer();
        ServerSocket socket = new ServerSocket(1234);
		Socket sock = socket.accept();
		InputStreamReader IR = new InputStreamReader(sock.getInputStream());
		BufferedReader BR = new BufferedReader(IR);
		
		String MESSAGE = BR.readLine();
		//System.out.println(MESSAGE);
		
		if(MESSAGE.equals(key))
		{
			System.out.println(MESSAGE);
			PrintStream PS = new PrintStream(sock.getOutputStream());
			String address = "10.2.0.2";
			//MESSAGE = BR.readLine();
            try
            {
                InetAddress IP = InetAddress.getByName(address);
                //PS.println("Hello " + "10.2.0.2");
                //PS.println("Your IP address is " + IP.getHostAddress());
				PS.println(key);
                String s = server.XOREncrypt("Hello");
                PS.println(s);

				MESSAGE = BR.readLine();
				MESSAGE = server.XOREncrypt(MESSAGE);
				System.out.println(MESSAGE);
            }
            catch(UnknownHostException e)
            {
                System.err.println(address + " unknown host");
            }
		}
		else
		{
			System.out.println("Keys are different, cannot do Diffie-Hellman");
		}
	}

	public String XOREncrypt(String s) {
		char key = 'G';

		String output = "";

		int characs = s.length();

		for(int i = 0; i < characs; i++) {
			output += Character.toString(((char)(s.charAt(i))^key)%8);
		}
		return output;
	}
}
