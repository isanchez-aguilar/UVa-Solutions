/*
*	User: Isanchez_Aguilar
*	Problem: UVA 447 - Population Explosion
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

inline bool isInside(int x, int y)
{
	return x > -1 and x < 20 and y > -1 and y < 20;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vvc moon;
	const int vecinos[8][2] = {
		{-1, -1},
		{-1,  0},
		{-1,  1},
		{ 0, -1},
		{ 0,  1},
		{ 1, -1},
		{ 1,  0},
		{ 1,  1}
	};

	int testCases;
	cin >> testCases;
	
	while (testCases--)
	{
		int years;
		
		cin >> years;
		cin.ignore();

		string line;
		moon = vvc(20, vector<char>(20, ' '));

		while (getline(cin, line) and line.length())
		{
			int x;
			int y;
			istringstream in(line);

			in >> x >> y;
			moon[x - 1][y - 1] = 'O';
		}

		cout << "********************\n";

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
				cout << moon[i][j];
			cout << "\n";
		}

		cout << "********************\n";

		for (int year = 1; year < years; ++year)
		{
			vvc backup = moon;
			
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					int neighbors = 0;
					
					for (int v = 0; v < 8; ++v)
					{
						int x = i + vecinos[v][0];
						int y = j + vecinos[v][1];

						if (isInside(x, y) and moon[x][y] == 'O')
							++neighbors;
					}

					if (moon[i][j] == 'O')
					{
						if (neighbors >= 4 or neighbors <= 1)
							backup[i][j] = ' ';

					}
					else if (	neighbors == 3)
						backup[i][j] = 'O';

					cout << backup[i][j];
				}
				
				cout << "\n";
			}

			moon = backup;
			cout << "********************\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}