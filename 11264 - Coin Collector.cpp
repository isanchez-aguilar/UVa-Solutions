/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11264 - Coin Collector
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
		int n;
		cin >> n;

		int sum = 0;
		int previous = 0; 
		int maximumCoins = 0;

		for(int i = 0; i < n; ++i)
		{
			int coin;
			cin >> coin;

			if(sum + previous < coin)
			{
				++maximumCoins;
				sum += previous;
			}

			previous = coin;
		}

		cout << maximumCoins << "\n";
	}

	return 0;
}