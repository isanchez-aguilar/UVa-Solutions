/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10576 - Y2K Accounting Bug
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int s;
	int d;
	while(cin >> s >> d)
	{
		// Maximum months of surplus for 5 months to get a deficit.
		int monthsSurplus = 5 * d / (s + d);
		// If there is not months of surplus is a deficit.
		if(monthsSurplus < 1)
		{
			cout << "Deficit\n";
			continue;
		}
		// Maximum months of deficit for 5 months to get a deficit
		int monthsDeficit = 5 - monthsSurplus;

		int total = 0;
		int currentMonth = 0;

		while(currentMonth < 12)
		{
			int availableMonths = min(monthsSurplus, 12 - currentMonth);
			
			total += s * availableMonths;
			currentMonth += availableMonths;
				
			availableMonths = min(monthsDeficit, 12 - currentMonth);
			total -= d * availableMonths;
			currentMonth += availableMonths;
		}

		if(total < 0)
			cout << "Deficit" << "\n";
		else
			cout << total << "\n";
	}

	return 0;
}