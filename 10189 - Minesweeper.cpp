/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10189 - Minesweeper
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int m;
	int i = 1;
	while(cin >> n >> m && n && m)
	{
		char current;
		// Initialize the field with 0 mines as neighbors.
		vvi field(n, vi(m, 0));
		// Read the field.
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < m; ++k)
			{
				cin >> current;
				// If the current box is a mine then increase 1 mine to it neighbors.
				if(current == '*')
				{
					// Box whit mine is equal to 1.
					field[j][k] = -1;
					for(int y = j - 1; y < j + 2; ++y)
					{
						for(int x = k - 1; x < k + 2; ++x)
						{
							if(x < m && x > -1 && y < n && y > -1 && (x != k || y != j) && field[y][x] != -1)
									++field[y][x];
						}
					}
				}
			}
		}

		if(i > 1)
			cout << '\n';
		cout << "Field #" << i++ << ":\n";
		
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < m; ++k)
			{
				// If the current box is -1 then is a mine.
				if(field[j][k] == -1)
					cout << '*';
				else
					cout << field[j][k];
			}
			cout << '\n';
		}
	}
	return 0;
}
