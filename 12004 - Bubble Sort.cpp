/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12004 - Bubble Sort
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	long long n;
	long long swaps;
	for (int t = 1; t <= testCases; ++t)
	{
		cin >> n;
		swaps = (n * (n - 1 )) >> 1LL;
		if (swaps & 1LL)
			cout << "Case " << t << ": " << swaps << "/2\n";
		else
			cout << "Case " << t << ": " << (swaps >> 1LL) << "\n";
	}

	return 0;
}