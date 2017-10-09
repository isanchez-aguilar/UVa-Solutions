/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10337 - Flight Planner
*/
#include <bits/stdc++.h>

using namespace std;

int X;
int w[10][100001];
int memo[10][100001];

inline int getMinFuel(int y, int x)
{
	if(y < 0 or y > 9 or X < x)
		return 100001;
	
	if(x == X)
	{
		if(y == 0)
			return 0;

		return 100001;
	}

	int &c = memo[y][x];

	if(c != -1)
		return c;

	return c = min(60 - w[y][x] + getMinFuel(y + 1, x + 1), min(30 - w[y][x] + getMinFuel(y, x + 1), 20 - w[y][x] + getMinFuel(y - 1, x + 1)));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		cin >> X;
		X /= 100;

		for(int y = 9; y >= 0; --y)
		{
			for(int x = 0; x < X; ++x)
				cin >> w[y][x];
		}

		memset(memo, -1, sizeof(memo));
		cout << getMinFuel(0, 0) << "\n\n";
	}

	return 0;
}