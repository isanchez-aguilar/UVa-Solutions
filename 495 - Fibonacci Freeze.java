/*
*	User: Isanchez_Aguilar
*	Problem: UVA 495 - Fibonacci Freeze
*/
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		int size = 2;
		Scanner scanner = new Scanner(System.in);
		BigInteger fibonacci[] = new BigInteger[5001];
		fibonacci[0] = BigInteger.valueOf(0);
		fibonacci[1] = BigInteger.valueOf(1);
		fibonacci[2] = BigInteger.valueOf(1);
		
		while(scanner.hasNext()) {
			int n = scanner.nextInt();
			if(size < n)
			{
				for (; size <= n; ++size)
					fibonacci[size] = fibonacci[size - 1].add(fibonacci[size - 2]);
				--size;
			}
			System.out.printf("The Fibonacci number for %d is %s\n", n, fibonacci[n].toString());
		}
	}
}