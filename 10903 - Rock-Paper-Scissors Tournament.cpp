/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10903 - Rock-Paper-Scissors Tournament
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int k;
	int p1;
	int p2;
	int t = 0;
	char m1[9];
	char m2[9];
	float win[101];
	float lose[101];
	while(cin >> n && n)
	{
		if(t++)
			cout << "\n";
		cin >> k;
		k = k * (n - 1) * n >> 1;
		// Initializing player data.
		for(int i = 0; i <= n; ++i)
		{
			win[i] = 0.0;
			lose[i] = 0.0;
		}
		// Read game data.
		while(k--)
		{
			cin >> p1 >> m1 >> p2 >> m2;
			// Possible cases such that there is game won, lost or tied.
			switch(m1[0])
			{
				case 's':
					if(m2[0] == 'p')
					{
						++win[p1];
						++lose[p2];
					}
					else if(m2[0] == 'r')
					{
						++win[p2];
						++lose[p1];
					}
				break;
				case 'p':
					if(m2[0] == 's')
					{
						++win[p2];
						++lose[p1];
					}
					else if(m2[0] == 'r')
					{
						++win[p1];
						++lose[p2];
					}
				break;
				default:
					if(m2[0] == 'p')
					{
						++win[p2];
						++lose[p1];
					}
					else if(m2[0] == 's')
					{
						++win[p1];
						++lose[p2];
					}
			}
		}
		// Calculating the average number of games won by each player.
		for(int i = 1; i <= n; ++i)
		{
			float q = win[i] + lose[i];
			if(q)
			{
				cout << std::fixed;
				cout << setprecision(3) << win[i] / q << '\n';
			}
			else
				cout << "-\n";
		}
	}
	return 0;
}