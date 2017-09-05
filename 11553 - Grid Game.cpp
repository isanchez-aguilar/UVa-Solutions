/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11553 - Grid Game
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	int grid[8][8];
	int j[] = {0, 1, 2, 3, 4, 5, 6, 7};
	cin >> testCases;
	while(testCases--)
	{
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				cin >> grid[i][j];
		}

		int totalCandies = INT_MAX;

		do
		{
			int candies = 0;
			
			for(int i = 0; i < n; ++i)
				candies += grid[i][j[i]];
			
			totalCandies = min(totalCandies, candies);
		}while(next_permutation(j, j + n));

		if(testCases)
			sort(j, j + 8);

		printf("%d\n", totalCandies);
	}

	return 0;
}