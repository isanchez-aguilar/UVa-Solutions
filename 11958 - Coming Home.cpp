/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11958 - Coming Home
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		int buses;
		int currentH;
		int currentM;

		cin >> buses >> currentH;
		cin.ignore(1, ':');
		cin >> currentM;

		int minTime = INT_MAX;
		currentM += currentH * 60;

		for (int i = 0; i < buses; ++i)
		{
			int h;
			int m;
			int travelTime;

			cin >> h;
			cin.ignore(1, ':');
			cin >> m >> travelTime;

			m += h * 60;

			if (m < currentM)
				m += 1440;

			minTime = min(minTime, m - currentM + travelTime);
		}

		cout << "Case " << t << ": " << minTime << "\n";
	}

	return 0;
}