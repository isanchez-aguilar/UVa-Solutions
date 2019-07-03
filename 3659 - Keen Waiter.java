
// Working program with FastReader 
import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.math.BigInteger;
  
public class Main 
{ 
	static class FastReader 
	{ 
		BufferedReader br; 
		StringTokenizer st; 
  
		public FastReader() 
		{ 
			br = new BufferedReader(new
					 InputStreamReader(System.in)); 
		} 
  
		String next() 
		{ 
			while (st == null || !st.hasMoreElements()) 
			{ 
				try
				{ 
					st = new StringTokenizer(br.readLine()); 
				} 
				catch (IOException  e) 
				{ 
					e.printStackTrace(); 
				} 
			} 
			return st.nextToken(); 
		} 
  
		int nextInt() 
		{ 
			return Integer.parseInt(next()); 
		} 
	}
  
	public static void main(String[] args) 
	{ 
		FastReader in = new FastReader(); 
		int testCases = in.nextInt(); 
		BigInteger[] factorial = new BigInteger[41];
		
		factorial[0] = BigInteger.ONE;
		for (int i = 1; i < 41; ++i) {
			factorial[i] = factorial[i - 1].multiply(BigInteger.valueOf(i));
		}
		
		while (testCases-- > 0) 
		{
			int n = in.nextInt();
			
		   System.out.println(factorial[n]); 
		} 
	} 
} 
