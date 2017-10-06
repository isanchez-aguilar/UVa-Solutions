/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11517 - Exact Change
*/
#include <bits/stdc++.h>

#define MAX 1e4

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	int used[10001];

	cin >> testCases;
	while(testCases--)
	{
		int n;
		int m;
		cin >> n >> m;

		used[0] = 0;
		for(int j = 10000; j > 0; --j)
				used[j] = MAX;

		for(int i = 0; i < m; ++i)
		{
			int coin;
			cin >> coin;

			for(int j = 10000; j >= coin; --j)
				used[j] = min(used[j], used[j - coin] + 1);
		}

		int payment;
		for(payment = n; used[payment] == MAX; ++payment);

		cout << payment << " " << used[payment] << "\n";
	}

	return 0;
}