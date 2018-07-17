/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12439 - February 29
*/
#include <bits/stdc++.h>

using namespace std;

const string months[] = { 
	"January", "February", "March", "April",
	"May", "June", "July", "August", "September",
	"October", "November", "December"
};

inline int getIndexMonth(string m)
{
	for (int i = 0; i < 12; ++i)
	{
		if (m == months[i])
			return i;
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		int y1;
		int y2;
		int d1;
		int d2;
		string month;

		cin >> month >> d1;
		cin.ignore(1, ',');
		cin >> y1;

		int m1 = getIndexMonth(month);

		cin >> month >> d2;
		cin.ignore(1, ',');
		cin >> y2;

		int m2 = getIndexMonth(month);
		
		if (m1 <= 1)
			--y1;

		if (m2 < 1 or (m2 == 1 and d2 < 29))
			--y2;

		cout << "Case " << t << ": " << (y2 / 4 - y1 / 4) + (y2 / 400 - y1 / 400) - (y2 / 100	 - y1 / 100	) << "\n";
	}

	return 0;
}