/*
*	User: Isanchez_Aguilar
*	Problem: UVA 145 - Gondwanaland Telecom
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char type;
	const double costs[5][3] = {
		{0.1, 0.06, 0.02},
		{0.25, 0.15, 0.05},
		{0.53, 0.33, 0.13},
		{0.87, 0.47, 0.17},
		{1.44, 0.8, 0.3}
	};
	while (cin >> type and type != '#')
	{
		int hEnd;
		int mEnd;
		int hStart;
		int mStart;
		string number;
		
		cin >> number >> hStart >> mStart >> hEnd >> mEnd;
		
		if (hEnd < hStart or (hStart == hEnd and mEnd <= mStart))
			hEnd += 24;
		
		int minutes[3] = {0, 0, 0};
		int endMinutes = hEnd * 60 + mEnd;
		int startMinutes = hStart * 60 + mStart;

		for (int t = 0; t <= 2880; ++t)
		{
			if (startMinutes < t and t <= endMinutes)
			{
				if ((t >= 0 and  t <= 480) or (t >= 1321 and t <= 1920) or (t >= 2761 and t <= 3360))
					++minutes[2];
				else if ((t >= 1081 and  t <= 1320) or (t >= 2521 and t <= 2760))
					++minutes[1];
				else
					++minutes[0];
			}
		}

		double total = 0;
		cout << setfill(' ') << setw(10) << number; 
		for (int i = 0; i < 3; ++i)
		{
			cout << setfill(' ') << setw(6) << minutes[i];
			total += minutes[i] * costs[type - 'A'][i];
		}
		
		cout << "  " << type << setfill(' ') << setw(8) << fixed << setprecision(2) << total << "\n";
	}
	
	return 0;
}
