/*
*	User: Isanchez_Aguilar
*	Problem: UVA 334 - Identifying Concurrent Events
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		UVA334 solver = new UVA334();
		solver.solve(1, in, out);
		out.close();
	}

	static class UVA334 {
		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int n;
			ArrayList<Pair> event = new ArrayList<>();
			ArrayList<String> names = new ArrayList<>();
			ArrayList<Pair> concurrentEvent = new ArrayList<>();
			Map<String, Integer> idEvent = new HashMap<String, Integer>();

			while ((n = in.nextInt()) != 0) {
				event.clear();
				names.clear();
				idEvent.clear();
				concurrentEvent.clear();

				for (int i = 0; i < n; ++i) {
					int m = in.nextInt();
					String name = in.next();
					int lastId = idEvent.size();

					names.add(name);
					idEvent.put(name, lastId);
					for (int j = 1; j < m; ++j) {
						name = in.next();
						int id = idEvent.size();

						if (idEvent.containsKey(name)) {
							id = idEvent.get(name);
						} else {
							names.add(name);
							id = idEvent.size();
							idEvent.put(name, id);
						}

						event.add(new Pair(lastId, id));
						lastId = id;
					}
				}

				n = in.nextInt();

				for (int i = 0; i < n; ++i) {
					String name = in.next();
					int e1 = idEvent.size();

					if (idEvent.containsKey(name)) {
						e1 = idEvent.get(name);
					} else {
						names.add(name);
						idEvent.put(name, e1);
					}

					name = in.next();
					int e2 = idEvent.size();

					if (idEvent.containsKey(name)) {
						e2 = idEvent.get(name);
					} else {
						names.add(name);
						idEvent.put(name, e2);
					}

					event.add(new Pair(e1, e2));
				}

				boolean[][] isReachable = new boolean[idEvent.size()][idEvent.size()];
				for (int i = 0; i < idEvent.size(); ++i)
					Arrays.fill(isReachable[i], false);
				for (Pair e : event) {
					isReachable[(int) e.getKey()][(int) e.getValue()] = true;
				}

				for (int k = 0; k < idEvent.size(); ++k) {
					for (int i = 0; i < idEvent.size(); ++i) {
						for (int j = 0; j < idEvent.size(); ++j) {
							isReachable[i][j] = isReachable[i][j] || (isReachable[i][k] && isReachable[k][j]);
						}
					}
				}

				for (int i = 0; i < idEvent.size(); ++i) {
					for (int j = i + 1; j < idEvent.size(); ++j) {
						if (isReachable[i][j] || isReachable[j][i])
							continue;
						concurrentEvent.add(new Pair(i, j));
					}
				}

				if (concurrentEvent.isEmpty()) {
					out.printf("Case %d, no concurrent events.\n", testNumber++);
				} else {

					out.printf("Case %d, %d concurrent events:\n", testNumber++, concurrentEvent.size());
					out.printf("(%s,%s) ", names.get(concurrentEvent.get(0).getKey()), names.get(concurrentEvent.get(0).getValue()));
					if (concurrentEvent.size() < 2) {
						out.println();
					} else {
						out.printf("(%s,%s) \n", names.get(concurrentEvent.get(1).getKey()), names.get(concurrentEvent.get(1).getValue()));
					}
				}
			}
		}

	}

	static class Pair {
		private int key;
		private int value;

		public Pair() {

		}

		public Pair(int key, int value) {
			this.key = key;
			this.value = value;
		}

		public int getKey() {
			return key;
		}

		public int getValue() {
			return value;
		}

	}
}

