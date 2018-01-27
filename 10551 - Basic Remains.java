/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10551 - Basic Remains
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
		UVA10551 solver = new UVA10551();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA10551 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int n;
			while (in.hasNextInt()) {
				int b = in.nextInt();

				if (b == 0)
					break;

				BigInteger p = in.nextBigInteger(b);
				BigInteger q = in.nextBigInteger(b);

				out.println(p.mod(q).toString(b));
			}
		}

	}
}

