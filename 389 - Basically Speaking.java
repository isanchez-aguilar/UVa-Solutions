/*
*	User: Isanchez_Aguilar
*	Problem: UVA 389 - Basically Speaking
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
		UVA389 solver = new UVA389();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA389 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			while (in.hasNext()) {
				String numberFrom = in.next();
				int baseFrom = in.nextInt();
				int baseTo = in.nextInt();
				String numberTo = (new BigInteger(numberFrom, baseFrom)).toString(baseTo);

				if (numberTo.length() <= 7) {
					out.printf("%7s\n", numberTo.toUpperCase());
				} else {
					out.println("  ERROR");
				}
			}
		}

	}
}