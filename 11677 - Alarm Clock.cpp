/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11677 - Alarm Clock
*/
#include <bits/stdc++.h>

#define parseMinutes(h) h*60

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h1;
	int h2;
	int m1;
	int m2;

	while (cin >> h1 >> m1 >> h2 >> m2 and (h1 or m1 or h2 or m2))
	{
		int minutes = 0;
		m1 += parseMinutes(h1);
		m2 += parseMinutes(h2);

		if (m1 > m2)
			m2 += 1440;

		cout << m2 - m1 << "\n";
	}

	return 0;
}