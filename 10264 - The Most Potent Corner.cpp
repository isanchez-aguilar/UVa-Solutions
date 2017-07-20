/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10264 - The Most Potent Corner
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n)
	{
		int corners = (1 << n);
		vector<int> weights(corners);
		for(int i = 0; i < corners; ++i)
			cin >> weights[i];
		
		vector<int> potency(corners);
		for(int i = 0; i < corners; ++i)
		{
			int currentPotency = 0;
			for(int j = 0; j < n; ++j)
			{
				int k = i ^ (1 << j);
				currentPotency += weights[k];
			}
			potency[i] = currentPotency;
		}

		int maxPotencySum = 0;
		for(int i = 0; i < corners; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int k = i ^ (1 << j);
				maxPotencySum = max(maxPotencySum, potency[i] + potency[k]);
			}
		}

		cout << maxPotencySum << "\n";
	}

	return 0;
}