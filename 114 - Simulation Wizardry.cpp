/*
*	User: Isanchez_Aguilar
*	Problem: UVA 114 - Simulation Wizardry
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	int bumpers;
	int wallCost;
	const int directions[][2] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}
	};
	cin >> n >> m >> wallCost >> bumpers;

	int x;
	int y;
	int v;
	int c;
	vector<vii> value(m, vii(n));
	vector< vector<bool> > isBumper(m, vector<bool>(n));
	
	for (int i = bumpers - 1; i >= 0; --i)
	{
		cin >> y >> x >> v >> c;

		isBumper[x - 1][y - 1] = true;
		value[x - 1][y - 1] = ii(v, c);
	}

	int lifeTime;
	int direction;
	int totalScore = 0;
	while (cin >> y >> x >> direction >> lifeTime)
	{
		--x;
		--y;
		int score = 0;
		while (--lifeTime > 0)
		{
			int x1 = x + directions[direction][0];
			int y1 = y + directions[direction][1];
			
			if (x1 <= 0 or x1 >= m - 1 or y1 <= 0 or y1 >= n - 1)
			{
				lifeTime -= wallCost;
				direction = (direction + 3) % 4; 
			}

			else if (isBumper[x1][y1])
			{
				score += value[x1][y1].first;
				direction = (direction + 3) % 4; 
				lifeTime -= value[x1][y1].second;
			}
			else
			{
				x = x1;
				y = y1;
			}
		}
		
		totalScore += score;
		cout << score << "\n";
	}

	cout << totalScore << "\n";

	return 0;
}