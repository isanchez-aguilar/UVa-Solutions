/*
*	User: Isanchez_Aguilar
*	Problem: UVA 104 - Arbitrage
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
		UVA104 solver = new UVA104();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA104 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			while (in.hasNextInt()) {

				int n = in.nextInt();
				int[][][] parent = new int[n][n][n];
				double[][][] dist = new double[n][n][n];

				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (i != j) {
							dist[i][j][0] = in.nextDouble();
						} else {
							dist[i][j][0] = 1.0;
						}

						parent[i][j][0] = i;
					}
				}
				for (int s = 1; s < n; ++s) {
					for (int k = 0; k < n; ++k) {
						for (int u = 0; u < n; ++u) {
							for (int v = 0; v < n; ++v) {
								double d = dist[u][k][s - 1] * dist[k][v][0];

								if (dist[u][v][s] < d) {
									dist[u][v][s] = d;
									parent[u][v][s] = k;
								}
							}
						}
					}
				}

				boolean isProfit = false;

				for (int s = 1; s < n && !isProfit; ++s) {
					for (int u = 0; u < n; ++u) {
						if (dist[u][u][s] > 1.01) {
							isProfit = true;
							int[] profit = new int[s + 1];
							profit[s] = parent[u][u][s];
							for (int j = s - 1; j >= 0; --j)
								profit[j] = parent[u][profit[j + 1]][j];
							for (int j = 0; j <= s; j++) {
								out.printf("%d ", profit[j] + 1);
							}
							out.println(profit[0] + 1);
							break;
						}
					}
				}

				if (!isProfit)
					out.println("no arbitrage sequence exists");
			}
		}

	}
}

