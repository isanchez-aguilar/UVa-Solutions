/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1262 - Password
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int n;
		cin >> n;

		bitset<26> grid1[6];
		bitset<26> grid2[6];

		for(int i = 0; i < 30; ++i)
		{
			char character;
			cin >> character;
			grid1[i % 5][character - 'A'] = true;
		}

		for(int i = 0; i < 30; ++i)
		{
			char character;
			cin >> character;
			grid2[i % 5][character - 'A'] = true;
		}

		vector<char> grid[5];

		for(int i = 0; i < 5; ++i)
		{
			for(int j = 0; j < 26; ++j)
			{
				if(grid1[i][j] and grid2[i][j])
					grid[i].push_back(j + 'A');
			}
		}
		
		int combinations = 1;
		for(int i = 0; i < 5; ++i)
			combinations *= grid[i].size();

		if(combinations < n)
			cout << "NO\n";
		else
		{
			for(int i = 0; n and i < grid[0].size(); ++i)
			{
				for(int j = 0; n and j < grid[1].size(); ++j)
				{
					for(int k = 0; n and k < grid[2].size(); ++k)
					{
						for(int l = 0; n and l < grid[3].size(); ++l)
						{
							for(int m = 0; n and m < grid[4].size(); ++m)
							{
								if(--n == 0)
									cout << grid[0][i] << grid[1][j] << grid[2][k] << grid[3][l] << grid[4][m] << "\n";	
							}							
						}
					}
				}
			}
		}	
	}

	return 0;
}