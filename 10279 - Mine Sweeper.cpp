/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10279 - Mine Sweeper
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 0; t < testCases; ++t)
	{
		int n;
		cin >> n;
		bool finish = false;
		vii field(n, vi(n, 0));
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				char current;
				cin >> current;
				// If the current is a mine add 1 to it neighbors.
				if(current == '*')
				{
					field[i][j] = -1;
					for(int k = i - 1; k < i + 2; ++k)
					{
						if(k > -1 && k < n)
						{
							for(int l = j - 1; l < j + 2; ++l)
							{
								if(l > -1 && l < n && field[k][l] != -1)
									++field[k][l];
							}
						}
					}
				}
			}
		}
		// Check game status if It is ended or still in progress.
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				char current;
				cin >> current;
				if(current == 'x' && field[i][j] == -1)
					finish = true;
				if(current == '.' && field[i][j] > -1)
					field[i][j] = -2;
			}
		}
		if(t > 0)
			cout << "\n";
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(field[i][j] == -1)
				{
					if(finish)
						cout << "*";
					else
						cout << ".";
				}
				else if(field[i][j] == -2)
					cout << ".";
				else
					cout << field[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}