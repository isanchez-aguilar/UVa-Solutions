/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10523 - Very Easy !!!
*/
import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String []args) {
		Scanner scanner = new Scanner(System.in);

		while(scanner.hasNext()) {
			BigInteger n = BigInteger.valueOf(scanner.nextInt());
			BigInteger a = BigInteger.valueOf(scanner.nextInt());
			/* 
			* The sum of A^i , i = 1 to N is equal to (A * (A^N - 1)) / (A - 1) and if you derive both sides
			* we get the sum of i * A^i / A, i = 1 to N is equal to (N * A^(N + 1) - (N + 1) * A^N + 1) / (A - 1)^2
			* the the sum of i * A^i, i = 1 to N is equal to (A * ((N * (A - 1) - 1) * A^N + 1)) / (A - 1)^2.
			*/
			int A = a.intValue();
			if(A == 0) {
				System.out.println("0");
			}
			else {
				BigInteger p;
				BigInteger q;
				if(A != 1) {	
					p =  a.multiply( (((n.multiply(a.subtract(BigInteger.valueOf(1)))).subtract(BigInteger.valueOf(1))).multiply(a.pow(n.intValue()))).add(BigInteger.valueOf(1)) );
					q = a.subtract(BigInteger.valueOf(1)).pow(2);
				}
				else {
					p = (n.add(BigInteger.valueOf(1))).multiply(n);
					q = BigInteger.valueOf(2);
				}
				System.out.println((p.divide(q)).toString());
			}
		}
	}
}