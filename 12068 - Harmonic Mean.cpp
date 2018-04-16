/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12068 - Harmonic Mean
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
		int s;
		cin >> s;

		long long value[s];

		for (int i = 0; i < s; ++i)
		{
			cin >> value[i];
		}

		int i = 1;
		long long lcm = value[0];

		while (i < s)
			lcm = lcm * value[i] / __gcd(lcm, value[i++]);

		long long sum = 0;
		for (int i = 0; i < s; ++i)
			sum += lcm / value[i];

		long long gcd = __gcd(lcm * s, sum);

		cout << "Case " << t << ": " << lcm * s / gcd << "/" << sum / gcd << endl;
	}

	return 0;
}