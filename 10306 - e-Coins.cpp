/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10306 - e-Coins
*/
#include <bits/stdc++.h>

#define MAX 1e4

using namespace std;

int emodulus;
int memo[301][301][40];
pair<int, int> coordinates[40];

int getNumberOfCoins(int x, int y, int availablePairs)
{
	int currentEmodulus = x * x + y * y;
	if(currentEmodulus == emodulus)
		return 0;
	
	if(currentEmodulus > emodulus or availablePairs < 0)
		return MAX;

	int &c = memo[x][y][availablePairs];

	if(c)
		return c;

	return c = min(getNumberOfCoins(x, y, availablePairs - 1), 1 + getNumberOfCoins(x + coordinates[availablePairs].first, y + coordinates[availablePairs].second, availablePairs)); 
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	
	while(testCases--)
	{
		int pairs;

		cin >> pairs >> emodulus;
		
		for(int i = 0; i < pairs; ++i)
			cin >> coordinates[i].first >> coordinates[i].second;

		emodulus *= emodulus;
		memset(memo, 0, sizeof(memo));
		int pairOfCoins = getNumberOfCoins(0, 0, pairs - 1);

		if(pairOfCoins == MAX)
			cout << "not possible\n";
		else
			cout << pairOfCoins << "\n";
	}

	return 0;
}