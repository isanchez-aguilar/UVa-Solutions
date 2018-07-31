/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11760 - Brother Arif, Please feed us!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const int adj[5][2] = {
		{ 0 , 0},
		{ 0, -1},
		{-1,  0},
		{ 1,  0},
		{ 0,  1}
	};
	int r;
	int c;
	int n;
	int t = 0;	
	bool availableRow[10000];
	bool availableColumn[10000];

	while (cin >> r >> c >> n and (r or c or n))
	{
		memset(availableRow, true, sizeof availableRow);
		memset(availableColumn, true, sizeof availableColumn);

		for (int i = 0; i < n; ++i)
		{
			int x;
			int y;

			cin >> x >> y;
			availableRow[x] = false;
			availableColumn[y] = false;
		}

		int i;
		int j;

		cin >> i >> j;
		bool scape = false;
		
		for (int m = 0; m < 5; ++m)
		{
			int x = i + adj[m][0];
			int y = j + adj[m][1];

			if (x > -1 and x < r and y > -1 and y < c and availableRow[x] and availableColumn[y])
			{
				scape = true;
				break;
			}
		}

		cout << "Case " << ++t << ": ";

		if (scape)
			cout << "Escaped again! More 2D grid problems!\n";
		else
			cout << "Party time! Let's find a restaurant!\n";
	}

	return 0;
}