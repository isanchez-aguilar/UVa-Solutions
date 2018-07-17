/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11219 - How old are you?
*/
#include <bits/stdc++.h>

#define y first
#define m second.first
#define d second.second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		int day;
		int year;
		int month;

		cin >> day;
		cin.ignore(1, '/');
		cin >> month;
		cin.ignore(1, '/');
		cin >> year;

		iii date2(year, ii(month, day));

		cin >> day;
		cin.ignore(1, '/');
		cin >> month;
		cin.ignore(1, '/');
		cin >> year;

		iii date1(year, ii(month, day));

		bool invalid = date1 > date2;

		cout << "Case #" << t << ": ";

		if (invalid)
			cout << "Invalid birth date\n";
		else
		{
			int age = date2.y - date1.y;
			
			if (date1.m > date2.m or (date1.m == date2.m and date1.d > date2.d))
				--age;

			if(age > 130)
				cout << "Check birth date\n";
			else
				cout << age << "\n";
		}
	}

	return 0;
}