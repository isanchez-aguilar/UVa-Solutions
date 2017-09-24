/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10755 - Garbage Heap
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	long long memo[21][21][21];

	cin >> testCases;
	while(testCases--)
	{
		int a;
		int b;
		int c;
		cin >> a >> b >> c;

		for(int i = 0; i < a; ++i)
		{
			for(int j = 0; j < b; ++j)
			{
				for(int k = 0; k < c; ++k)
				{
					long long value;
					cin >> value;

					if(i > 0)
						value += memo[i - 1][j][k];
					if(j > 0)
						value += memo[i][j - 1][k];
					if(k > 0)
						value += memo[i][j][k - 1];
					if(i > 0 and j > 0)
						value -= memo[i - 1][j - 1][k];
					if(i > 0 and k > 0)
						value -= memo[i - 1][j][k - 1];
					if(j > 0 and k > 0)
						value -= memo[i][j - 1][k - 1];
					if(i > 0 and j > 0 and k > 0)
						value += memo[i - 1][j - 1][k - 1];

					memo[i][j][k] = value;
				}
			}
		}

		long long maxSum = INT_MIN;

		for(int i = 0; i < a; ++i)
		{
			for(int j = 0; j < b; ++j)
			{
				for(int k = 0; k < c; ++k)
				{
					for(int x = i; x < a; ++x)
					{
						for(int y = j; y < b; ++y)
						{
							for(int z = k; z < c; ++z)
							{							
								long long currentSum = memo[x][y][z];

								if(i > 0)
									currentSum -= memo[i - 1][y][z];
								if(j > 0)
									currentSum -= memo[x][j - 1][z];
								if(k > 0)
									currentSum -= memo[x][y][k - 1];
								if(i > 0 and j > 0)
									currentSum += memo[i - 1][j - 1][z];
								if(i > 0 and k > 0)
									currentSum += memo[i - 1][y][k - 1];
								if(j > 0 and k > 0)
									currentSum += memo[x][j - 1][k - 1];
								if(i > 0 and j > 0 and k > 0)
									currentSum -= memo[i - 1][j - 1][k - 1];
					
								maxSum = max(maxSum, currentSum);
							}
						}
					}
				}
			}
		}

		cout << maxSum << "\n";
		if(testCases)
			cout << "\n";	
	}

	return 0;
}