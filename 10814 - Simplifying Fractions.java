/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10814 - Simplifying Fractions
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
		UVA10814 solver = new UVA10814();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class UVA10814 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			BigInteger p = in.nextBigInteger();
			String slash = in.next();
			BigInteger q = in.nextBigInteger();
			BigInteger gcd = p.gcd(q);
			out.println(p.divide(gcd) + " " + slash + " " + q.divide(gcd));
		}

	}
}

