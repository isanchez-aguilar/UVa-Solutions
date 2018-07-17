/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11650 - Mirror Clock
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int h;
		int m;

		cin >> h;
		cin.ignore(1, ':');
		cin >> m;

		h = 11 - h;
		m = 60 - m;

		if (m == 60)
		{
			++h;
			m = 0;
		}
		
		if (h <= 0)
			h += 12;

		cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << "\n";
	}

	return 0;
}