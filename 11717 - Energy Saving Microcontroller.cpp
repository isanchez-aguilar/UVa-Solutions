/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11717 - Energy Saving Microcontroller
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		int n;
		int i;
		int k;
		cin >> n >> i >> k;

		int activeTime = 0;
		int inactivateStates = 0;
		int ignoredInstructions = 0;

		while (n--)
		{
			int m;
			cin >> m;

			if (activeTime + i <= m)
			{
				++inactivateStates;
				activeTime = m + k;
			}

			else if (m < activeTime)
				++ignoredInstructions;
			else
				activeTime = m;
		}

		cout << "Case " << t << ": " << inactivateStates << " " << ignoredInstructions << "\n";
	}

	return 0;
}