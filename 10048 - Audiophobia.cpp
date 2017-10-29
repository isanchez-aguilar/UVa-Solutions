/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10048 - Audiophobia
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	int s;
	int q;
	int t = 0;
	int d[101][101];

	while(cin >> c >> s >> q and (c or s or q))
	{
		for(int i = 0; i <= c; ++i)
		{
			for(int j = 0; j <= c; ++j)
				d[i][j] = INT_MAX;
		}

		for(int i = 0; i < s; ++i)
		{
			int a;
			int b;
			int decibels;
			cin >> a >> b >> decibels;

			d[a][b] = decibels;
			d[b][a] = decibels;
		}

		for(int k = 1; k <= c; ++k)
		{
			for(int i = 1; i <= c; ++i)
			{
				for(int j = 1; j <= c; ++j)
				{
					d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
					d[j][i] = d[i][j];
				}
			}
		}

		if(t++)
			cout << "\n";

		cout << "Case #" << t << "\n";

		for(int i = 0; i < q; ++i)
		{
			int a;
			int b;
			
			cin >> a >> b;

			if(d[a][b] == INT_MAX)
				cout << "no path\n";
			else
				cout << d[a][b] << "\n";
		}
	}

	return 0;
}