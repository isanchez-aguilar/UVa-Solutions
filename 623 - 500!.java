import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main (String[] args)  {
		int n;
		Scanner in = new Scanner(System.in);
		BigInteger[] factorial = new BigInteger[1001];

		factorial[0] = BigInteger.ONE;

		for (int i = 1; i < 1001; ++i)
			factorial[i] = BigInteger.valueOf(i).multiply(factorial[i - 1]);

		while (in.hasNextInt()) {
			n = in.nextInt();
			System.out.println(n + "!\n" + factorial[n]);
		}
		
	}
}