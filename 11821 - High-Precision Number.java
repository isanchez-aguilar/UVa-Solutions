/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11821 - High-Precision Number
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		UVA11821 solver = new UVA11821();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class UVA11821 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			BigDecimal n;
			BigDecimal ans = BigDecimal.ZERO;

			while ((in.hasNextBigDecimal())) {
				n = in.nextBigDecimal();
				if (n.equals(BigDecimal.ZERO)) {
					out.println(ans.stripTrailingZeros().toPlainString());
					break;
				}

				ans = ans.add(n);
			}
		}

	}
}