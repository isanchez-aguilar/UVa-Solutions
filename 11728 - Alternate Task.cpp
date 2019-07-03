/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11728 - Alternate Task
*/
#include <bits/stdc++.h>

using namespace std;

int prime[1001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(prime, -1, sizeof prime);

	for (int i = 0; i < 1001; ++i)
	{
		int sum = 0;

		for (int j = 2; j <= i; ++j)
		{
			if (i % j == 0)
				sum += j;
		}

		if (sum < 1000)
			prime[sum + 1] = max(prime[sum + 1], i);
	}

	int n;
	int t = 0;

	while (cin >> n and n)
		cout << "Case " << ++t << ": " << prime[n] << "\n";

	return 0;
}