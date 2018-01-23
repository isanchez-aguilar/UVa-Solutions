/*
*	User: Isanchez_Aguilar
*	Problem: 10171 - Meeting Prof. Miguel...
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
		UVA10171 solver = new UVA10171();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA10171 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int n;
			int[][] adjMe = new int[27][27];
			int[][] distMe = new int[27][27];
			int[][] adjProf = new int[27][27];
			int[][] distProf = new int[27][27];

			while ((n = in.nextInt()) != 0) {
				for (int i = 0; i < 27; ++i) {
					Arrays.fill(distMe[i], (int) 1e6);
					Arrays.fill(distProf[i], (int) 1e6);
				}

				for (int i = 0; i < n; ++i) {
					char age = in.next("[A-Z]").charAt(0);
					char direction = in.next("[A-Z]").charAt(0);
					int u = in.next("[A-Z]").charAt(0) - 'A';
					int v = in.next("[A-Z]").charAt(0) - 'A';
					int cost = in.nextInt();

					if (age == 'Y') {
						distMe[u][v] = cost;

						if (direction == 'B')
							distMe[v][u] = cost;
					}

					if (age == 'M') {
						distProf[u][v] = cost;

						if (direction == 'B')
							distProf[v][u] = cost;
					}

				}

				int sMe = in.next("[A-Z]").charAt(0) - 'A';
				int sProf = in.next("[A-Z]").charAt(0) - 'A';

				for (int k = 0; k < 27; ++k) {
					distMe[k][k] = 0;
					distProf[k][k] = 0;
					for (int u = 0; u < 27; ++u) {
						for (int v = 0; v < 27; ++v) {
							distMe[u][v] = Integer.min(distMe[u][v], distMe[u][k] + distMe[k][v]);
							distProf[u][v] = Integer.min(distProf[u][v], distProf[u][k] + distProf[k][v]);
						}
					}
				}

				int minCost = (int) 1e6;

				for (int i = 0; i < 27; ++i) {
					if (distMe[sMe][i] < (int) 1e6 && distProf[sProf][i] < (int) 1e6) {
						int dist = distMe[sMe][i] + distProf[sProf][i];
						if (dist < minCost) {
							minCost = distMe[sMe][i] + distProf[sProf][i];
						}
					}
				}

				if (minCost < (int) 1e6) {
					out.print(minCost);
					for (int i = 0; i < 27; ++i) {
						int dist = distMe[sMe][i] + distProf[sProf][i];
						if (dist == minCost) {
							char c = (char) (i + 'A');
							out.print(" " + c);
						}
					}
					out.println();
				} else {
					out.println("You will never meet.");
				}

			}
		}

	}
}