/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10339 - Watching Watches
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	int m;
	
	while (cin >> k >> m)
	{
		// Difference between watches to know gap of watches.
		unsigned int gap = max(m, k) - min(m, k);
		/* 
		 * Computation to know the passed seconds to match both watches. Applying the seconds lost on a day
		 * and multiplying by 43200(time to match correct hour) and dividing by the gap time and module of
		 * 12 hours(in seconds) and adding 30 seconds to round nearest minute.
		*/
		unsigned int seconds = (43200 * (86400 - k) / gap) % 43200 + 30;
		// Seconds converted to hours.
		int hour = seconds / 3600 % 12;
		// Seconds converted to minutes.
		int minutes = seconds / 60 % 60;

		cout << k << " " << m << " " << setfill('0') << setw(2) << (hour?hour:12) << ":" << setfill('0') << setw(2) << minutes << "\n";
	}
	
	return 0;
}
