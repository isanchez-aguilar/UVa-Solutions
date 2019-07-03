import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {

		int t = 0;
		int items;
		BigInteger friends;
		Scanner in = new Scanner(System.in);
		
		while (in.hasNextInt()) {
			items = in.nextInt();
			friends = in.nextBigInteger();

			if (items == 0 && friends.equals(BigInteger.ZERO))
				break;

			BigInteger sum = BigInteger.ZERO;


			for (int i = 0; i < items; ++i)
				sum = sum.add(in.nextBigInteger());

			++t;
			System.out.println("Bill #" + t + " costs " + sum + ": each friend should pay " + sum.divide(friends) + "\n");
		}
	}
}