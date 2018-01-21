/*
*	User: Isanchez_Aguilar
*	Problem: UVA 821 - Page Hopping
*/
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		
		int t = 0;
		String line = "";
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		while (!(line = input.readLine()).equals("0 0")) {
			int[][] dist = new int[100][100];

			for (int i = 0; i < 100; ++i) {
				for (int j = 0; j < 100; ++j)
					dist[i][j] = (int) 1e6;
				
				dist[i][i] = 0;
			}

			String[] numbers = line.split(" ");

			for (int i = 0; i < numbers.length - 2; i += 2) {
				int a = Integer.parseInt(numbers[i]) - 1;
				int b = Integer.parseInt(numbers[i + 1]) - 1;

				dist[a][b] = 1;
			}

			for (int k = 0; k < 100; ++k) {
				for (int u = 0; u < 100; ++u) {
					for (int v = 0; v < 100; ++v) {
						dist[u][v] = Integer.min(dist[u][v], dist[u][k] + dist[k][v]);
					}
				}
			}

			int suma = 0;
			int total = 0;
			
			for (int u = 0; u < 100; ++u) {
				for (int v = 0; v < 100; ++v) {
					if (u != v && dist[u][v] != 1e6) {
						++total;
						suma += dist[u][v];
					}
				}
			}

			System.out.printf("Case %d: average length between pages = %.3f clicks\n", ++t, (double) suma / total);
		}
	}
}
