/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11505 - Logo
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		UVA11505 solver = new UVA11505();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class UVA11505 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			double dx = 0.0;
			double dy = 0.0;
			double angle = 0.0;
			int n = in.nextInt();

			for (int i = 0; i < n; ++i) {
				String command = in.next();
				double dist = in.nextDouble();

				switch (command.charAt(0)) {
					case 'l':
						angle += dist;
						angle %= 360.0;
						break;
					case 'r':
						angle -= dist;
						angle %= 360.0;
						break;
					case 'f':
						dx += (dist * Math.cos(Math.toRadians(angle)));
						dy += (dist * Math.sin(Math.toRadians(angle)));
						break;
					default:
						dx -= (dist * Math.cos(Math.toRadians(angle)));
						dy -= (dist * Math.sin(Math.toRadians(angle)));
				}
			}

			out.println(Math.round(Math.hypot(dx, dy)));
		}
	}
}
