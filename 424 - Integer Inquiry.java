import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String[] args) {

		BigInteger n;
		BigInteger sum = BigInteger.ZERO;
		Scanner in = new Scanner(System.in);
		
		while (in.hasNext()) {
			n = in.nextBigInteger();
			sum = sum.add(n);
		}
		
		System.out.println(sum);
	}
}