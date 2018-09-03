/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10474 - Where is the Marble?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int q;
	int t = 0;

	while (cin >> n >> q and (n or q))
	{
		int marble[n];
		
		for (int i = 0; i < n; ++i)
			cin >> marble[i];
		
		sort(marble, marble + n);

		cout << "CASE# " << ++t << ":\n";

		for (int i = 0; i < q; ++i)
		{
			int value;
			cin >> value;
			
			int* p = lower_bound(marble, marble + n, value);

			if (p == marble + n or *p != value)
				cout << value << " not found\n";
			else
				cout << value << " found at " << (p - marble + 1) << "\n";
		}
	}

	return 0;
}