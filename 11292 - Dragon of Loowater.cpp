/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11292 - Dragon of Loowater
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int heads;
	int knights;
	while(cin >> heads >> knights and (heads or knights))
	{
		vector<int> h(heads);
		vector<int> k(knights);

		for(int i = 0; i < heads; ++i)
			cin >> h[i];

		for(int i = 0; i < knights; ++i)
			cin >> k[i];

		sort(h.begin(), h.end());
		sort(k.begin(), k.end());

		int coins = 0;
		bool possible = true;

		for(int i = 0, j = 0; i < heads; ++i)
		{
			while(j < knights and k[j] < h[i])
				++j;

			if(j == knights)
			{
				possible = false;
				break;
			}

			coins += k[j++];
		}

		if(possible)
			cout << coins << "\n";
		else
			cout << "Loowater is doomed!\n";		
	}

	return 0;
}