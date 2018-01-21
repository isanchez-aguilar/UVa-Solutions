/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11947 - Cancer or Scorpio
*/
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.GregorianCalendar;

public class Main11947 {

	public static void main(String[] args) throws IOException {
		final int[] hash = {21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};
		final String[] sign = {"aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius", "capricorn"};
		
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(input.readLine());

		for(int t = 1; t <= testCases; ++t) {
			String line = input.readLine();

			int month = Integer.parseInt(line.substring(0, 2));
			int day = Integer.parseInt(line.substring(2, 4));
			int year = Integer.parseInt(line.substring(4));

			GregorianCalendar date = new GregorianCalendar(year, month - 1, day);
			date.add(GregorianCalendar.WEEK_OF_YEAR, 40);

			month = date.get(GregorianCalendar.MONTH);
			day = date.get(GregorianCalendar.DAY_OF_MONTH);
			year = date.get(GregorianCalendar.YEAR);

			System.out.printf("%d %02d/%02d/%04d ", t, (month + 1), day, year);

			if (hash[month] > day)
				--month;

			System.out.println(sign[month < 0?11:month]);
		}
	}
}
