/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10858 - Unique Factorization
*/
#include <bits/stdc++.h>

using namespace std;

typedef set<int> si;
typedef vector<int> vi;

si divisors;
vector<vi> factorizations;

inline void getFactorizations(int n, si::iterator i, vi factors)
{
	if (n == 1)
	{
		factorizations.push_back(factors);
		return;
	}
	
	while (i != divisors.end())
	{
		const int& d = *i;

		if (n % d == 0 and (d == n or d <= n / d))
		{
			factors.push_back(d);
			getFactorizations(n / d, i, factors);
			factors.pop_back();
		}

		++i;
	}
	
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n and n)
	{
		divisors.clear();
		int sqRoot = sqrt(n);

		for (int i = 2; i <= sqRoot; ++i)
		{
			if (n % i == 0)
			{
				divisors.insert(i);
				
				if (i * i != n)
					divisors.insert(n / i);
			}
		}

		factorizations.clear();

		if (n > 1)
			getFactorizations(n, divisors.begin(), vi());

		cout << factorizations.size() << "\n";
		
		for (int i = 0; i < factorizations.size(); ++i)
		{
			for (int j = 0; j < factorizations[i].size(); ++j)
				cout << factorizations[i][j] << (j + 1 == factorizations[i].size()?"\n":" ");
		}
	}

	return 0;
}