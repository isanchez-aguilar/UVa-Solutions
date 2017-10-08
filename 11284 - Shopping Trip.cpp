/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11284 - Shopping Trip
*/
#include <bits/stdc++.h>

using namespace std;

int operas;
int cost[51][51];
int storePrice[14];
int storeNumber[14];
int memo[14][16385];

inline int searchBestDifference(int index, int used)
{
	if(used == (1 << operas) - 1)
		return -cost[0][storeNumber[index]];

	int &c = memo[index][used];
	
	if(c != -1)
		return c;

	c = -cost[0][storeNumber[index]];
	for(int i = 0; i < operas; ++i)
	{
		if(not(used & (1 << i)))
		{
			int v = storePrice[i] - cost[storeNumber[i]][storeNumber[index]];
			v += searchBestDifference(i, used | (1 << i));
			c = max(c, v); 
		}
	}

	return c;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int roads;
		int stores;
		cin >> stores >> roads;
		
		++stores;
		for(int i = 0; i < 51; ++i)
		{
			for(int j = 0; j < 51; ++j)
				cost[i][j] = 1e8;

			cost[i][i] = 0;
		}

		for(int i = 0; i < roads; ++i)
		{
			int a;
			int b;
			double c;
			cin >> a >> b >> c;

			cost[a][b] = min(cost[b][a], (int)round(c * 100.0));
			cost[b][a] = cost[a][b];
		}

		for(int k = 0; k < stores; ++k)
		{
			for(int i = 0; i < stores; ++i)
			{
				for(int j = 0; j < stores; ++j)
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}

		cin >> operas;

		++operas;
		storePrice[0] = 0;
		storeNumber[0] = 0;
		
		for(int i  = 1; i < operas; ++i)
		{
			double c;
			cin >> storeNumber[i] >> c;
			storePrice[i] = (int)round(c * 100.0);
		}
		
		memset(memo, -1, sizeof(memo));
		int difference = searchBestDifference(0, 1);

		if(difference <= 0)
			cout << "Don't leave the house\n";
		else
			cout << "Daniel can save $" << difference / 100 << "." << setw(2) << setfill('0') << difference % 100 << "\n"; 
	}

	return 0;
}