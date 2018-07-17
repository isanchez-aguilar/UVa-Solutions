/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12019 - Doom's Day Algorithm
*/
import java.util.Scanner;
import java.util.GregorianCalendar;

class Main {
	public static void main(String[] args) {
		
		final String[] days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

		Scanner input = new Scanner(System.in);

		int testCases = input.nextInt();

		while (testCases-- > 0) {

			int month = input.nextInt();
			int day = input.nextInt();

			GregorianCalendar date = new GregorianCalendar(2011, month - 1, day);

			day = date.get(GregorianCalendar.DAY_OF_WEEK);
			

			System.out.println(days[day - 1]);
		}
	}
}