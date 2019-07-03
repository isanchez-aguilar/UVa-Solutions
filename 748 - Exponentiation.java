import java.util.Scanner;
import java.math.BigDecimal;

class Main {
	public static void main(String[] args) {

		int n;
		BigDecimal r;
		Scanner in = new Scanner(System.in);
		
		while (in.hasNext()) {
			r = in.nextBigDecimal();
			n = in.nextInt();

			int i = 0;
			String answer = r.pow(n).stripTrailingZeros().toPlainString();
			
			while (answer.charAt(i) == '0')
				++i;

			System.out.println(answer.substring(i));
		}
	}
}