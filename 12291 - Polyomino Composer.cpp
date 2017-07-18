/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12291 - Polyomino Composer
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	while(cin >> m >> n && (m || n))
	{
		int squaresB = 0;
		int squaresS = 0;
		vector<string> big(m);

		for(int i = 0; i < m; ++i)
			cin >> big[i];

		int minIb = m;
		int minJb = m;
		int maxJb = -1;
		int maxIb = -1;

		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(big[i][j] == '*')
				{
					++squaresB;
					minIb = min(minIb, i);
					maxIb = max(maxIb, i + 1);
					minJb = min(minJb, j);
					maxJb = max(maxJb, j + 1);
				}
			}
		}


		vector<string> small(n);
		for(int i = 0; i < n; ++i)
			cin >> small[i];

		int minIs = n;
		int minJs = n;
		int maxJs = -1;
		int maxIs = -1;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(small[i][j] == '*')
				{
					++squaresS;
					minIs = min(minIs, i);
					maxIs = max(maxIs, i + 1);
					minJs = min(minJs, j);
					maxJs = max(maxJs, j + 1);
				}
			}
		}
		int appearances = 0;
		if((squaresS << 1) == squaresB)
		{
			int diffI = maxIs - minIs;
			int diffJ = maxJs - minJs;

			for(int i = minIb; i <= maxIb - diffI && appearances != 2; ++i)
			{
				for(int j = minJb; j <= maxJb - diffJ && appearances != 2; ++j)
				{
					bool isSame = 1;
					for(int k = i; k < i + diffI && isSame; ++k)
					{
						int y = k - i + minIs;
						for(int l = j; l < j + diffJ; ++l)
						{
							int x = l - j + minJs;

							if(small[y][x] == '*' && small[y][x] != big[k][l])
							{
								isSame = 0;
								break;
							}

						}
					}
					if(isSame)
					{
						for(int k = i; k < i + diffI && isSame; ++k)
						{
							int y = k - i + minIs;
							for(int l = j; l < j + diffJ; ++l)
							{
								int x = l - j + minJs;

								if(small[y][x] == '*')
									big[k][l] = '.';

							}
						}
						++appearances;
					}
				}
			}
		}
		if(appearances == 2)
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}