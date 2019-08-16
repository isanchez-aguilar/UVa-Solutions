/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10465 - Homer Simpson
*/
#include <bits/stdc++.h>

#define INF 1000000

using namespace std;
using Long = int;

int t;
Long m, n;
vector<Long> memo;
vector<bool> visited;

void canReach(int currTime)
{
	visited[currTime] = true;

	if (currTime + n <= t and not visited[currTime + n])
		canReach(currTime + n);

	if (currTime + m <= t and not visited[currTime + m])
		canReach(currTime + m);

	return;
}

Long getMaxBurgers(int currTime)
{
	if (memo[currTime] == -1)
	{
		Long way1 = -1;
		Long way2 = -1;

		if (m <= currTime)
			way1 = getMaxBurgers(currTime - m);
		if (n <= currTime)
			way2 = getMaxBurgers(currTime - n);

		int maxWay = max(way1, way2);

		if (maxWay >= 0)
			memo[currTime] = 1 + maxWay;
		else
			memo[currTime] = -INF;
	}

	return memo[currTime];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> m >> n >> t)
	{
		visited = vector<bool>(t + 1, false);
		memo = vector<Long>(t + 1, -1);

		canReach(0);
		memo[0] = 0;

		if (visited[t])
			cout << getMaxBurgers(t) << "\n";
		else
		{

			for (int i = t - 1; i >= 0; --i)
			{
				if (visited[i])
				{
					cout << getMaxBurgers(i) << " " << t - i << "\n";
					break;
				}
			}
		}
	}

	return 0;
}