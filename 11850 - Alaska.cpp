/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11850 - Alaska
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int stations;
	while(cin >> stations && stations)
	{
		vector<int> positions(stations);

		for(int i = 0; i < stations; ++i)
			cin >> positions[i];
		
		sort(positions.begin(), positions.end());

		if(positions[0] <= 200)
		{
			bool possible = 1;	
			for(int i = 1; i < stations; ++i)
			{
				if(positions[i] - positions[i - 1] > 200)
				{
					possible = 0;
					break;
				}
			}

			if(possible && 1322 <= positions[stations - 1])
				cout << "POSSIBLE\n";
			else
				cout << "IMPOSSIBLE\n";
		}
		else
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}