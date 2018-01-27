/*
*	User: Isanchez_Aguilar
*	Problem: UVA 763 - Fibinary Numbers
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		UVA763 solver = new UVA763();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA763 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			BigInteger[] fib = new BigInteger[110];
			fib[0] = BigInteger.ONE;
			fib[1] = new BigInteger("2");

			for (int i = 2; i < 110; ++i)
				fib[i] = fib[i - 1].add(fib[i - 2]);

			while (in.hasNext()) {
				String n1 = (new StringBuilder(in.next()).reverse().toString());
				String n2 = (new StringBuilder(in.next()).reverse().toString());
				int maxLength = Integer.max(n1.length(), n2.length());

				BigInteger ans = BigInteger.ZERO;
				for (int i = 0; i < maxLength; ++i) {
					if (i < n1.length())
						ans = ans.add(fib[i].multiply((n1.charAt(i) == '0' ? BigInteger.ZERO : BigInteger.ONE)));
					if (i < n2.length())
						ans = ans.add(fib[i].multiply((n2.charAt(i) == '0' ? BigInteger.ZERO : BigInteger.ONE)));
				}
				if (1 < testNumber++)
					out.println();
				if (ans.equals(BigInteger.ZERO)) {
					out.println("0");
				} else {
					boolean isBiggerBit = false;
					for (int i = 109; i > -1; --i) {
						if (ans.compareTo(fib[i]) >= 0) {
							out.print("1");
							ans = ans.subtract(fib[i]);
							isBiggerBit = true;
						} else if (isBiggerBit) {
							out.print("0");
						}
					}
					out.println();
				}
			}
		}

	}
}