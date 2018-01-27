/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11287 - Pseudoprime Numbers
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
		UVA11287 solver = new UVA11287();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA11287 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			BigInteger p;
			BigInteger a;

			while (!(p = in.nextBigInteger()).equals(BigInteger.ZERO)) {
				a = in.nextBigInteger();

				if (a.isProbablePrime(10) && p.isProbablePrime(10))
					out.println("no");
				else {
					if (a.modPow(p, p).equals(a))
						out.println("yes");
					else
						out.println("no");
				}
			}
		}

	}
}

