/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12148 - Electricity
*/
#include <bits/stdc++.h>

using namespace std;

inline bool isLeapYear(int year)
{
	return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n and n)
	{
		int previousD = 0;
		int previousM = 0;
		int previousY = 0;
		int previousC = 0;

		int consecutive = 0;
		unsigned long long totalConsumption = 0;

		for (int i = 0; i < n; ++i)
		{
			int d;
			int m;
			int y;
			int c;

			cin >> d >> m >> y >> c;
			
			// If previous date is 31-Dec and current 1-Jan.
			if (previousD == 31 and previousM == 12 and d == 1 and m == 1 and y - previousY == 1)
			{
				++consecutive;
				totalConsumption += c - previousC;
			}
			// If It is the same year.
			else if (previousY == y)
			{
				
				// If It is the same month.
				if (previousM == m)
				{
					// If It is the next day from previous.
					if (d - previousD == 1)
					{
						++consecutive;
						totalConsumption += c - previousC;
					}
				}

				// If It is the next month from previous.
				else if (m - previousM == 1 and d == 1)
				{
					// If previous date is 31-Jan and current 1-Feb.
					bool isNext = (previousM == 1 and previousD == 31);
					// If previous year is not leap and date is 28-Feb and current 1-Mar.
					isNext = isNext or (not isLeapYear(previousY) and previousM == 2 and previousD == 28);
					// If previous year is leap and date is 29-Feb and current 1-Mar.
					isNext = isNext or (isLeapYear(previousY) and previousM == 2 and previousD == 29);
					// If previous date is 31-Mar and current 1-Apr.
					isNext = isNext or (previousM == 3 and previousD == 31);
					// If previous date is 30-Apr and current 1-May.
					isNext = isNext or (previousM == 4 and previousD == 30);
					// If previous date is 31-May and current 1-Jun.
					isNext = isNext or (previousM == 5 and previousD == 31);
					// If previous date is 30-Jun and current 1-Jul.
					isNext = isNext or (previousM == 6 and previousD == 30);
					// If previous date is 31-Jul and current 1-Aug.
					isNext = isNext or (previousM == 7 and previousD == 31);
					// If previous date is 31-Aug and current 1-Sep.
					isNext = isNext or (previousM == 8 and previousD == 31);
					// If previous date is 30-Sep and current 1-Oct.
					isNext = isNext or (previousM == 9 and previousD == 30);
					// If previous date is 31-Oct and current 1-Nov.
					isNext = isNext or (previousM == 10 and previousD == 31);
					// If previous date is 30-Nov and current 1-Dec.
					isNext = isNext or (previousM == 11 and previousD == 30);

					if (isNext)
					{
						consecutive++;
						totalConsumption+=c - previousC;
					}
				}
			}

			previousD = d;
			previousM = m;
			previousY = y;
			previousC = c;
		}

		cout << consecutive << " " << totalConsumption << "\n";
	}

	return 0;
}