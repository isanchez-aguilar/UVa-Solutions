/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11356 - Dates
*/
import java.util.Scanner;
import java.util.GregorianCalendar;

class Main {
	public static void main(String[] args) {
		
		final String[] months = { 
			"January", "February", "March", "April",
			"May", "June", "July", "August", "September",
			"October", "November", "December"
		};

		Scanner input = new Scanner(System.in);

		int testCases = input.nextInt();

		for (int t = 1; t <= testCases; ++t) {
			String[] data = input.next().split("-", 3);

			int year = Integer.parseInt(data[0]);

			int month = 0;
			String m = data[1];
			
			for (int i = 0; i < 12; ++i) {
				if (months[i].equals(m)) {
					month = i;
					break;
				}
			}

			int day = Integer.parseInt(data[2]);

			GregorianCalendar date = new GregorianCalendar(year, month, day);

			date.add(GregorianCalendar.DAY_OF_MONTH, input.nextInt());

			year = date.get(GregorianCalendar.YEAR);
			month = date.get(GregorianCalendar.MONTH);
			day = date.get(GregorianCalendar.DAY_OF_MONTH);
			

			System.out.printf("Case %d: %04d-%s-%02d\n", t, year, months[month], day);
		}
	}
}