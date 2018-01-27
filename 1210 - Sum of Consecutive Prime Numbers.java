/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1210 - Sum of Consecutive Prime Numbers
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		UVA1210 solver = new UVA1210();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA1210 {
		final int MAX = 10001;

		public void solve(int testNumber, Scanner in, PrintWriter out) {
			boolean[] isNotPrime = new boolean[MAX];
			ArrayList<Integer> primes = new ArrayList<>();

			primes.add(2);
			isNotPrime[0] = true;
			isNotPrime[1] = true;
			isNotPrime[2] = false;

			for (int i = 4; i < MAX; i += 2)
				isNotPrime[i] = true;

			for (int i = 3; i < MAX; i += 2) {
				if (!isNotPrime[i]) {
					primes.add(i);

					for (int j = i << 1; j < MAX; j += i) {
						isNotPrime[j] = true;
					}
				}
			}

			int[] representations = new int[MAX];

			for (int i = 0; i < primes.size(); ++i) {
				int sum = 0;
				for (int j = i; j < primes.size(); ++j) {
					sum += primes.get(j);

					if (MAX <= sum) {
						break;
					}
					++representations[sum];
				}
			}

			int n;
			while ((n = in.nextInt()) != 0) {
				out.println(representations[n]);
			}
		}

	}
}