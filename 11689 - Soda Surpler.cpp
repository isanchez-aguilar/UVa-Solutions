/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11689 - Soda Surpler
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int initial;
		int found;
		int change;
		cin >> initial >> found >> change;

		initial += found;
		int total = 0;

		while (initial % change != initial)
		{
			int bottles = initial / change;
			total += bottles;
			initial %= change;
			initial += bottles;
		}
		cout << total << "\n";
	}

	return 0;
}