/*
*	User: Isanchez_Aguilar
*	Problem: UVA 665 - False coin
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	bitset<100> real; 
	for(int t = 0; t < testCases; ++t)
	{
		int coins;
		int tests;
		real.reset();
		cin >> coins >> tests;

		for(int i = 0; i < tests; ++i)
		{
			int tested;
			cin >> tested;
			tested <<= 1;
			vector<int> testedCoins(tested);
			
			for(int j = 0; j < tested; ++j)
				cin >> testedCoins[j];

			char outcome;
			cin >> outcome;
			
			switch(outcome)
			{
				case '=':
					for(int j = 0; j < tested; ++j)
						real[testedCoins[j] - 1] = 1;
				break;
			}
		}

		int f = -1;
		for(int i = 0; i < coins; ++i)
		{
			if(!real[i])
			{
				if(f == -1)
					f = i;
				else
				{
					f = -1;
					break;
				}
			}
		}

		if(t)
			cout << "\n";
		if(f == -1)
			cout << "0\n";
		else
			cout << f + 1 << "\n";
	}

	return 0;
}