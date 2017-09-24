/*
*	User: Isanchez_Aguilar
*	Problem: UVA 108 - Maximum Sum
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int memo[100][100];
	while(cin >> n)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				int value;
				cin >> value;
				
				if(i > 0)
					value += memo[i - 1][j];
				if(j > 0)
					value += memo[i][j - 1];
				if(i > 0 and j > 0)
					value -= memo[i - 1][j - 1];

				memo[i][j] = value;
			}
		}

		int maximumSum = INT_MIN;
		
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				for(int x = i; x < n; ++x)
				{
					for(int y = j; y < n; ++y)
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