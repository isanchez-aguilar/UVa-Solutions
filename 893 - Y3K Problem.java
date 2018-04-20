/*
*	User: Isanchez_Aguilar
*	Problem: UVA 893 - Y3K Problem
*/
import java.util.*;

public class Main {

	public static void main(String args[]) {
		int N;
		int d;
		int m;
		int y;
		Scanner in = new Scanner(System.in);
		
		while (true){
			N = in.nextInt();
			d = in.nextInt();
			m = in.nextInt();
			y = in.nextInt();

			if (N == 0 && d == 0 && m == 0 && y == 0)
				break;
				
			GregorianCalendar date = new GregorianCalendar(y , m - 1, d);
			
			date.add(Calendar.DATE, N);
			
			System.out.println(date.get(Calendar.DATE) + " " + (date.get(Calendar.MONTH) + 1) + " " + date.get(Calendar.YEAR));
		}
	}
}
