/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10102 - The path in the colored field
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	while(cin >> m)
	{
		vector<string> board(m);
		
		for(int i = 0; i < m; ++i)
			cin >> board[i];

		int maxDistance = -1;
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(board[i][j] == '1')
				{
					int minDistance = INT_MAX;
					for(int k = 0; k < m; ++k)
					{
						for(int l = 0; l < m; ++l)
						{
							if(board[k][l] == '3')
								minDistance = min(minDistance, abs(i - k) + abs(j - l));
						}
					}
					maxDistance = max(maxDistance, minDistance);
				}
			}
		}

		cout << maxDistance << "\n";
	}

	return 0;
}