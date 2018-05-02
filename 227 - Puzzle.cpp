/*
*	User: Isanchez_Aguilar
*	Problem: UVA 227 - Puzzle
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int t = 0;
	char puzzle[5][5];
	while (getline(cin, s) and s != "Z")
	{
		int x;
		int y;
		for (int i = 0; i < 5; ++i)
		{
			if (s[i] == ' ')
			{
				x = 0;
				y = i;
			}
			puzzle[0][i] = s[i];
		}

		for (int i = 1; i < 5; ++i)
		{
			getline(cin, s);
			for (int j = 0; j < 5; ++j)
			{
				if (s[j] == ' ')
				{
					x = i;
					y = j;
				}
				puzzle[i][j] = s[j];
			}
		}

		char c;
		bool illegal = false;
		while (cin >> c and c != '0')
		{
			if (not illegal)
			{
				switch(c)
				{
					case 'A':
						if (x > 0)
						{
							puzzle[x][y] ^= puzzle[x - 1][y];
							puzzle[x - 1][y] ^= puzzle[x][y];
							puzzle[x][y] ^= puzzle[x - 1][y];
							--x;
						}
						else
							illegal = true;
					break;
					case 'B':
						if (x < 4)
						{
							puzzle[x][y] ^= puzzle[x + 1][y];
							puzzle[x + 1][y] ^= puzzle[x][y];
							puzzle[x][y] ^= puzzle[x + 1][y];
							++x;
						}
						else
							illegal = true;
					break;
					case 'L':
						if (y > 0)
						{
							puzzle[x][y] ^= puzzle[x][y - 1];
							puzzle[x][y - 1] ^= puzzle[x][y];
							puzzle[x][y] ^= puzzle[x][y - 1];
							--y;
						}
						else
							illegal = true;
					break;
					case 'R':
						if (y < 4)
						{
							puzzle[x][y] ^= puzzle[x][y + 1];
							puzzle[x][y + 1] ^= puzzle[x][y];
							puzzle[x][y] ^= puzzle[x][y + 1];
							++y;
						}
						else
							illegal = true;
					break;
					default:
						illegal = true;
				}
			}
		}

		cin.ignore();
		if (t++)
			cout << "\n";
		cout << "Puzzle #" << t << ":\n";
		
		if (illegal)
			cout << "This puzzle has no final configuration.\n";
		else
		{
			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
					cout << puzzle[i][j] << (j + 1 == 5?"\n":" ");
			}
		}	
	}

	return 0;
}