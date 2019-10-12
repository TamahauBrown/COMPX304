import java.io.*;
import java.net.*;
import java.security.*;

public class SimpleClient
{
	public static void main(String [] args) throws Exception
	{
		String key = args[0];
		SimpleClient client = new SimpleClient();
		client.run(key);
	}
		
		public void run(String key) throws Exception
		{
			SimpleClient client = new SimpleClient();
			InetAddress IP = InetAddress.getByName("10.2.0.2");
			Socket socket = new Socket("localhost", 1234);
			PrintStream PS = new PrintStream(socket.getOutputStream());
			PS.println(key);
			
			InputStreamReader IR = new InputStreamReader(socket.getInputStream());
			BufferedReader BR = new BufferedReader(IR);
			
			String message = BR.readLine();

			if(message.equals(key)) {
				//Send an encrypted message
				String s = client.XOREncrypt("Tamahau");
				PS.println(s);

				message = BR.readLine();
				message = client.XOREncrypt(message);
				System.out.println(message);
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
			output += Character.toString(((char)(s.charAt(i))^key)%8);		}
		return output;
	}
	}

