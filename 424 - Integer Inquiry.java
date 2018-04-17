/*
*	User: Isanchez_Aguilar
*	Problem: UVA 424 - Integer Inquiry
*/
import java.util.Scanner;
import java.math.BigInteger;

public class UVA424 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger ans = new BigInteger("0");

		while (in.hasNextBigInteger()) {
			BigInteger n = in.nextBigInteger();
			
			if (n.equals(BigInteger.ZERO))
				break;
			
			ans = ans.add(n);
		}

		System.out.println(ans);
	}
}