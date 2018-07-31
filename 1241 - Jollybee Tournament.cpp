/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1241 - Jollybee Tournament
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	bitset<1024> available;

	while (testCases--)
	{
		int n;
		int m;

		cin >> n >> m;
		int size = 1 << n;
		
		for (int i = 0; i < size; ++i)
			available.set(i, true);

		for (int i = 0; i < m; ++i)
		{
			int player;
			cin >> player;
			available.set(player - 1, false);
		}

		int walkOver = 0;

		while (size > 1)
		{
			for (int i = 0; i < size; i += 2)
			{
				if (available[i])
				{
					if (not available[i + 1])
						++walkOver;

					available.set(i >> 1, true);
				}
				else
				{
					if (available[i + 1])
					{
						++walkOver;
						available.set(i >> 1, true);
					}
					else
						available.set(i >> 1, false);			
				}
			}

			size >>= 1;
		}
		
		cout << walkOver << "\n";
	}

	return 0;
}