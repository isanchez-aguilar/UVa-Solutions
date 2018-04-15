/*
*	User: Isanchez_Aguilar
*	Problem: UVA 13187 - Felipe and the Sequence
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	int testCases;
	
	cin >> testCases;

	while (testCases--)
	{
		cin >> n;
		// Telescopic series.
		cout << (n + 1) * (n + 1) - 1 << "\n";
	}

	return 0;
}