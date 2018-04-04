/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10783 - Odd Sum
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	int b;
	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		cin >> a >> b;
		int sum = 0;
		for (int i = a; i <= b; ++i)
		{
			if (i & 1)
				sum += i;
		}
		cout << "Case " << t << ": " << sum << '\n';
	}

	return 0;
}