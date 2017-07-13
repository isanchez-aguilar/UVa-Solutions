/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11093 - Just Finish it up
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		int stations;		
		cin >> stations;

		vector<int> neighbors(stations);
		vector<int> requiredGas(stations);
		vector<int> availableGas(stations);
		for(int i = 0; i < stations; ++i)
		{
			cin >> availableGas[i];
			neighbors[i] = i + 1;
		}

		for(int i = 0; i < stations; ++i)
			cin >> requiredGas[i];
		
		bool isWay = 1;
		bool possible = 1;
		int minPosition = 0;
		int currentStation = 0;
		neighbors[stations - 1] = 0;

		for(int i = neighbors[0]; i != 0;)
		{
			isWay = 1;
			possible = 0;
			int difference = availableGas[i] - requiredGas[i];
			if(difference < 0)
				i = neighbors[i];
			else
			{
				possible = 1;
				for(int j = neighbors[i]; j != i; j = neighbors[j])
				{
					difference += availableGas[j] - requiredGas[j];
					if(difference < 0)
					{
						if(i < j)
							i = neighbors[j];
						else
							isWay = 0;
						possible = 0;
						break;
					}
				}
			}

			if(possible)
			{
				minPosition = i + 1;
				break;
			}
			if(!isWay)
			{
				minPosition = 0;
				break;
			}
		}

		cout << "Case " << t << ": ";
		if(possible)
			cout << "Possible from station " << minPosition << "\n";
		else
			cout << "Not possible" << "\n";
	}

	return 0;
}