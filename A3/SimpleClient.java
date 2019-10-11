import java.io.*;
import java.net.*;
import java.security.*;

public class SimpleClient
{
	public static void main(String [] args) throws Exception
	{
		SimpleClient client = new SimpleClient();
		client.run();
	}
		
		public void run() throws Exception
		{
			SimpleClient client = new SimpleClient();
			InetAddress IP = InetAddress.getByName("10.2.0.2");
			Socket socket = new Socket("localhost", 1234);
			PrintStream PS = new PrintStream(socket.getOutputStream());
			PS.println("Hello to SERVER from CLIENT.");
			
			InputStreamReader IR = new InputStreamReader(socket.getInputStream());
			BufferedReader BR = new BufferedReader(IR);
			
			String message = BR.readLine();
			System.out.println(message);
		}
	}

