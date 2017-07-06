/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11875 - Brick Game
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;

	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		int n;
		cin >> n;
		vector<int> ages(n);
		// Read ages.
		for(int i = 0; i < n; ++i)
			cin >> ages[i];
		// Sort ages.
		sort(ages.begin(), ages.end());
		// Get the age on the middle.
		cout << "Case " << t << ": " << ages[n >> 1] << '\n';
	}

	return 0;
}