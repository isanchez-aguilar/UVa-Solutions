/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10827 - Maximum sum on a torus
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	int memo[152][152];

	cin >> testCases;
	while(testCases--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < (n << 1); ++i)
		{
			for(int j = 0; j < (n << 1); ++j)
			{
				if(i < n and j < n)
				{
					cin >> memo[i][j];
					
					memo[i + n][j] = memo[i][j];
					memo[i][j + n] = memo[i][j];
					memo[i + n][j + n] = memo[i][j];
				}

				if(i > 0)
					memo[i][j] += memo[i - 1][j];
				if(j > 0)
					memo[i][j] += memo[i][j - 1];
				if(i > 0 and j > 0)
					memo[i][j] -= memo[i - 1][j - 1];
			}
		}

		int maximumSum = INT_MIN;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				for(int x = i; x < i + n; ++x)
				{
					for(int y = j; y < j + n; ++y)
					{
						int currentSum = memo[x][y];
						if(i > 0)
							currentSum -= memo[i - 1][y];
						if(j > 0)
							currentSum -= memo[x][j - 1];
						if(i > 0 and j > 0)
							currentSum += memo[i - 1][j - 1];
						
						maximumSum = max(maximumSum, currentSum);
					}
				}
			}
		}

		cout << maximumSum << "\n";
	}

	return 0;
}