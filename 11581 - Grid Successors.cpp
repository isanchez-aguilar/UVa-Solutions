/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11581 - Grid Successors
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	const int adj[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

	cin >> testCases;
	while(testCases--)
	{
		bool isZero = 1;
		vector< bitset<3> > grid(3);

		for(int i = 0; i < 3; ++i)
		{
			string row;
			cin >> row;
			for(int j = 0; j < 3; ++j)
			{
				grid[i][j] = row[j] - '0';
				if(grid[i][j])
					isZero = 0;
			}
		}

		if(isZero)
			cout << "-1\n";
		else
		{
			int sum = 1;
			int index = -1;
			vector< bitset<3> > temp(3);

			while(!isZero)
			{
				++index;
				isZero = 1;
				for(int i = 0; i < 3; ++i)
				{
					for(int j = 0; j < 3; ++j)
					{
						bool sum = 0;
						for(int m = 0; m < 4; ++m)
						{
							int y = i + adj[m][0];
							int x = j + adj[m][1];

							if(y > -1 && y < 3 && x > -1 && x < 3)
								sum = grid[y][x] ^ sum;
						}
						temp[i][j] = sum;
						if(temp[i][j])
							isZero = 0;
					}
				}
				grid = temp;
			}

			cout << index << "\n";
		}
	}

	return 0;
}