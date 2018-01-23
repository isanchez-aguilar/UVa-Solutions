/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11463 - Commandos
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
		UVA11463 solver = new UVA11463();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class UVA11463 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int n = in.nextInt();
			int m = in.nextInt();
			int[][] adj = new int[n][n];

			for (int i = 0; i < n; ++i) {
				Arrays.fill(adj[i], (int) 1e6);
				adj[i][i] = 0;
			}

			for (int i = 0; i < m; ++i) {
				int u = in.nextInt();
				int v = in.nextInt();

				adj[u][v] = 1;
				adj[v][u] = 1;
			}

			int s = in.nextInt();
			int t = in.nextInt();

			for (int k = 0; k < n; ++k) {
				for (int u = 0; u < n; ++u) {
					for (int v = 0; v < n; ++v) {
						adj[u][v] = Integer.min(adj[u][v], adj[u][k] + adj[k][v]);
					}
				}
			}

			int minCost = 0;

			for (int k = 0; k < n; ++k) {
				minCost = Integer.max(minCost, adj[s][k] + adj[k][t]);
			}

			out.printf("Case %d: %d\n", testNumber, minCost);
		}

	}
}

