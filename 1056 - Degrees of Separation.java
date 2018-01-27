/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1056 - Degrees of Separation
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		UVA1056 solver = new UVA1056();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA1056 {
		final int MAX = (int) 1e6;

		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int n;
			int m;
			while (in.hasNextInt()) {
				n = in.nextInt();
				m = in.nextInt();

				if (n == 0 && m == 0)
					break;

				int[][] dist = new int[n][n];
				for (int i = 0; i < n; ++i) {
					Arrays.fill(dist[i], MAX);
					dist[i][i] = 0;
				}

				Map<String, Integer> index = new HashMap<String, Integer>();

				for (int i = 0; i < m; ++i) {
					String uName = in.next();
					String vName = in.next();

					int u = index.size();

					if (index.get(uName) == null) {
						index.put(uName, u);
					} else {
						u = index.get(uName);
					}

					int v = index.size();

					if (index.get(vName) == null) {
						index.put(vName, v);
					} else {
						v = index.get(vName);
					}
					dist[u][v] = 1;
					dist[v][u] = 1;
				}

				for (int k = 0; k < n; ++k) {
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
							dist[i][j] = Integer.min(dist[i][j], dist[i][k] + dist[k][j]);
						}
					}
				}
				int maxDegree = 0;
				boolean disconnected = false;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						if (dist[i][j] >= MAX) {
							disconnected = true;
							break;
						}
						maxDegree = Integer.max(maxDegree, dist[i][j]);
					}
				}

				if (disconnected)
					out.printf("Network %d: DISCONNECTED\n\n", testNumber++);
				else
					out.printf("Network %d: %d\n\n", testNumber++, maxDegree);
			}
		}

	}
}

