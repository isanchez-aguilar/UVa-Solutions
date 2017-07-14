/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10050 - Hartals
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	bitset<3650> days;

	cin >> testCases;
	while(testCases--)
	{
		int simulationDays;
		int politicalParties;
		cin >> simulationDays >> politicalParties;
		
		vector<int> h(politicalParties);
		vector<int> currentDay(politicalParties, -1);

		for(int i = 0; i < politicalParties; ++i)
			cin >> h[i];

		int lostDays = 0;
		bool available = 1;

		while(available)
		{
			available = 0;
			for(int i = 0; i < politicalParties; ++i)
			{
				if(currentDay[i] < simulationDays - h[i])
				{
					available = 1;
					currentDay[i] += h[i];
					int d = currentDay[i] % 7;
					//cout << i << "," << currentDay[i] << " " << d;
					if(d != 5 && d != 6 && !days[currentDay[i]])
					{
						//cout << "+";
						days[currentDay[i]] = 1;
						++lostDays;						
					}
					//cout << endl;
				}
			}
		}

		if(testCases)
		{
			for(int i = 0; i < simulationDays; ++i)
				days[i] = 0;
		}
		
		cout << lostDays << "\n";
	}

	return 0;
}