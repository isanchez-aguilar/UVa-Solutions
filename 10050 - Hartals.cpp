/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10050 - Hartals
*/
#include <bits/stdc++.h>

using namespace std;

int h[100];
bitset<3650> days;
int currentDay[100];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int simulationDays;
		int politicalParties;
		cin >> simulationDays >> politicalParties;
		
		fill(currentDay, currentDay + politicalParties, -1);

		for (int i = 0; i < politicalParties; ++i)
			cin >> h[i];

		int lostDays = 0;
		bool available = true;

		while (available)
		{
			available = false;
			
			for (int i = 0; i < politicalParties; ++i)
			{
				if (currentDay[i] < simulationDays - h[i])
				{
					available = true;
					currentDay[i] += h[i];
					int d = currentDay[i] % 7;
					
					if (d != 5 and d != 6 and not days[currentDay[i]])
					{
						++lostDays;						
						days.set(currentDay[i], true);
					}
				}
			}
		}

		if (testCases)
			days.reset();
		
		cout << lostDays << "\n";
	}

	return 0;
}