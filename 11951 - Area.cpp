/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11951 - Area
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	long long memo[100][100];

	cin >> testCases;
	for(int t = 1; t <= testCases; ++t)
	{
		int n;
		int m;
		int k;
		cin >> n >> m >> k;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cin >> memo[i][j];
				
				if(i > 0)
					memo[i][j] += memo[i - 1][j];
				if(j > 0)
					memo[i][j] += memo[i][j - 1];
				if(i > 0 and j > 0)
					memo[i][j] -= memo[i - 1][j - 1];
			}
		}

		long long cost = 0;
		int maxArea = 0;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				for(int x = i; x < n; ++x)
				{
					for(int y = j; y < m; ++y)
					{
						long long currentCost = memo[x][y];
						int currentArea = (x - i + 1) * (y - j + 1);

						if(i > 0)
							currentCost -= memo[i - 1][y];
						if(j > 0)
							currentCost -= memo[x][j - 1];
						if(i > 0 and j > 0)
							currentCost += memo[i - 1][j - 1];

						if(maxArea < currentArea and currentCost <= k)
						{
							cost = currentCost;
							maxArea = currentArea;
						}
						else if(maxArea == currentArea and currentCost < cost)
							cost = currentCost;
					}
				}
			}
		}

		cout << "Case #" << t << ": " << maxArea << " " << cost << "\n";
	}

	return 0;
}