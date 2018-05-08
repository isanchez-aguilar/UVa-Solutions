/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10813 - Traditional BINGO
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef map<int, ii> miii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	miii index;
	int rows[5];
	int columns[5];
	int card[5][5];
	bool used[5][5];
	int diagonals[2];

	cin >> n;
	while (n--)
	{
		memset(rows, 0, sizeof rows);
		memset(columns, 0, sizeof columns);
		memset(diagonals, 0, sizeof diagonals);

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				used[i][j] = false;

				if (i == 2 and j == 2)
					continue;
				cin >> card[i][j];
				index[card[i][j]] = make_pair(i, j);
			}
		}

		bool bingo = false;
		
		for (int i = 0; i < 75; ++i)
		{
			ii p;
			int v;

			cin >> v;
			
			if (bingo)
				continue;
			
			if (index.count(v) > 0)
				p = index[v];
			else
				p = make_pair(2, 2);

			if (p == make_pair(2, 2))
			{
				if (not used[2][2])
				{	
					++rows[2];
					++columns[2];
					++diagonals[0];
					++diagonals[1];
				}
			}
			else
			{
				if (p.first == p.second)
					++diagonals[0];
				else if (p.first == 4 - p.second)
					++diagonals[1];

				if (++rows[p.first] == 5)
					bingo = true;
				if (++columns[p.second] == 5)
					bingo = true;
			}

			if (diagonals[0] == 5 or diagonals[1] == 5)
				bingo = true;

			if (bingo)
				cout << "BINGO after " << i + 1 << " numbers announced\n";

			used[p.first][p.second] = true;
		}

		if (n)
			index.clear();
	}

	return 0;
}