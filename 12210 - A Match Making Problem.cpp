/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12210 - A Match Making Problem
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int m;
	int t = 0;
	while(cin >> n >> m and (n or m))
	{
		vector<int> bachelor(n);
		vector<int> spinster(m);
		int minBachelor = INT_MAX;

		for(int i = 0; i < n; ++i)
		{
			cin >> bachelor[i];
			minBachelor = min(minBachelor, bachelor[i]);
		}

		for(int i = 0; i < m; ++i)
			cin >> spinster[i];

		cout << "Case " << ++t << ": ";
		if(n <= m)
			cout << "0\n";
		else
			cout << n - m << " " << minBachelor << "\n";
	}

	return 0;
}