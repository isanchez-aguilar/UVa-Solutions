/*
*	User: Isanchez_Aguilar
*	Problem: UVA 608 - Counterfeit Dollar
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		UVA608 solver = new UVA608();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class UVA608 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int[] up = new int[12];
			int[] down = new int[12];

			Arrays.fill(up, 0);
			Arrays.fill(down, 0);

			for (int i = 3; i > 0; --i) {
				String left = in.next();
				String right = in.next();
				String word = in.next();

				int leftUp = 0;
				int rightUp = 0;
				int leftDown = 0;
				int rightDown = 0;

				switch (word.charAt(0)) {
					case 'u':
						rightUp = 1;
						leftDown = 1;
						break;
					case 'd':
						leftUp = 1;
						rightDown = 1;
						break;
					default:
						leftUp = -1;
						rightUp = -1;
						leftDown = -1;
						rightDown = -1;
						break;
				}

				for (int j = 0; j < left.length(); ++j) {
					int c = left.charAt(j) - 'A';

					up[c] += leftUp;
					down[c] += leftDown;

					c = right.charAt(j) - 'A';

					up[c] += rightUp;
					down[c] += rightDown;
				}
			}

			char coin = ' ';
			int maxStatus = 0;
			boolean light = false;

			for (int i = 0; i < 12; ++i) {
				if (maxStatus < up[i]) {
					light = true;
					maxStatus = up[i];
					coin = (char) (i + 'A');
				}

				if (maxStatus < down[i]) {
					light = false;
					maxStatus = down[i];
					coin = (char) (i + 'A');
				}
			}

			out.println(coin + " is the counterfeit coin and it is " + (light ? "light." : "heavy."));
		}

	}
}

