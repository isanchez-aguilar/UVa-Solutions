/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10855 - Rotated square
*/
#include <bits/stdc++.h>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int m;

	while(cin >> n >> m && n && m)
	{
		vector<string> big(n);
		vector<string> small(m);
		int appearances[4] = {0};

		for(int i = 0; i < n; ++i)
			cin >> big[i];

		for(int i = 0; i < m; ++i)
			cin >> small[i];
		
		int difference = n - m;
		for(int i = 0; i <= difference; ++i)
		{
			for(int j = 0; j <= difference; ++j)
			{
				bool match0 = 1;
				bool match90 = 1;
				bool match180 = 1;
				bool match270 = 1;
				int iLimit = i + m;
				int jLimit = j + m;
				
				for(int k = i; k < iLimit; ++k)
				{
					int y = k - i;
					for(int l = j; l < jLimit; ++l)
					{
						int x = l - j;

						if(big[k][l] != small[y][x])
							match0 = 0;
						if(big[k][l] != small[m - 1 - x][y])
							match90 = 0;
						
						if(big[k][l] != small[m - 1 - y][m - 1 - x])
							match180 = 0;
						if(big[k][l] != small[x][m - 1 - y])
							match270 = 0;
					}
				}
				if(match0)
					++appearances[0];
				if(match90)
					++appearances[1];
				if(match180)
					++appearances[2];
				if(match270)
					++appearances[3];
			}
		}

		for(int i = 0; i < 4; ++i)
			cout << appearances[i] << (i + 1 < 4?" ":"\n");
	}

	return 0;
}