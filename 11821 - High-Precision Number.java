import java.util.Scanner;
import java.math.BigDecimal;

class Main {
	public static void main(String[] args) {

		BigDecimal n;
		BigDecimal sum = BigDecimal.ZERO;
		Scanner in = new Scanner(System.in);
		
		int testCases = in.nextInt();
		
		while (in.hasNext()) {
			n = in.nextBigDecimal();
			if (n.equals(BigDecimal.ZERO)) {
				System.out.println(sum.stripTrailingZeros().toPlainString());
				sum = BigDecimal.ZERO;
			}
			else
				sum = sum.add(n);
		}
		
	}
}