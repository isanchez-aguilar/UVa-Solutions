/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12398 - NumPuzz I
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string clicks;
	const int moves[5][2] = {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};

	for(int t = 1; getline(cin, clicks); ++t)
	{
		int length = clicks.length();
		vector< vector<int> > grid(3, vector<int>(3));

		for(int i = length - 1; i > -1; --i)
		{
			int y = (clicks[i] - 'a') / 3;
			int x = (clicks[i] - 'a') % 3;

			for(int m = 0; m < 5; ++m)
			{
				int y1 = y + moves[m][0];
				int x1 = x + moves[m][1];
				if(y1 > -1 && y1 < 3 && x1 > -1 && x1 < 3)
					grid[y1][x1] = (grid[y1][x1] + 1) % 10; 
			}
		}

		cout << "Case #" << t << ":\n";
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				cout << grid[i][j];
				if(j < 2)
					cout << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}