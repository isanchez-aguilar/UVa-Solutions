/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10880 - Colin and Ryan
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
		long c;
		long r;
		cin >> c >> r;

		set<long> divisors;
		long sqRoot = sqrt(c - r);
		
		if (c == r)
			divisors.insert(0);
		else
		{
			for (long i = 1; i <= sqRoot; ++i)
			{
				if ((c - r) % i == 0)
				{
					if (i > r)
						divisors.insert(i);
					if ((c - r) / i > r)
						divisors.insert((c - r) / i);
				}
			}
		}	

		cout << "Case #" << t << ":";
		
		for (set<long>::iterator i = divisors.begin(); i != divisors.end(); ++i)
			cout << " " << *i;

		cout << "\n";
	}

	return 0;
}