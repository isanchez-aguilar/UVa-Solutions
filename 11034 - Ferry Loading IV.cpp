/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11034 - Ferry Loading IV
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	
	while(testCases--)
	{
		int cars;
		int maxLong;
	
		cin >> maxLong >> cars;

		maxLong *= 100;
		vector<int> carLong(cars);
		vector< queue<int> > sides(2);
		
		for(int i = 0; i < cars; ++i)
		{
			int l;
			string side;
			cin >> l >> side;

			if(side[0] == 'l')
				sides[0].push(i);
			else
				sides[1].push(i);

			carLong[i] = l;
		}

		int side = 0;
		int moves = 0;

		while(!sides[0].empty() || !sides[1].empty())
		{
			int currentLong = 0;
			while(!sides[side].empty() && carLong[sides[side].front()] + currentLong <= maxLong)
			{
				currentLong += carLong[sides[side].front()];
				sides[side].pop();
			}
			++moves;
			side = (side + 1) % 2;
		}

		cout << moves << "\n";
	}

	return 0;
}