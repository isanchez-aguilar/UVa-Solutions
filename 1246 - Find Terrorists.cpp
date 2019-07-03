/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1246 - Find Terrorists
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

long long p;
long long result;
bool numbers[10001];
bool isNotPrime[MAX];
long long factor[MAX];
int numberPrimeFactors[10001];
vector<long long> prime(1, 2);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 4; i < MAX; i += 2)
		isNotPrime[i] = true;
	
	for (p = 3; p < MAX; p += 2)
	{
		if (not isNotPrime[p])
		{	
			factor[p] = p;
			prime.push_back(p);
		}

		for (int j = 0; j < prime.size() and p * prime[j] < MAX and prime[j] <= factor[p]; ++j)
		{
			factor[p * prime[j]] = prime[j];
			isNotPrime[p * prime[j]] = true;
		}
	}


	numberPrimeFactors[0] = 0;
	numberPrimeFactors[1] = 0;

	for (int i = 2; i < 10001; ++i)
	{
		int primeFactors = 0;
		
		for (int j = 1; j <= i; ++j)
		{
			if (i % j == 0)
				++primeFactors;
		}

		numberPrimeFactors[i] = numberPrimeFactors[i - 1];
		//cout << "\t" << i << " " << primeFactors << " " << isNotPrime[primeFactors] << endl;
		if (not isNotPrime[primeFactors])
		{
			numbers[i] = true;
			++numberPrimeFactors[i];
		}
	}

	int testCases;
	cin >> testCases;
	while (testCases--)
	{
		int l;
		int r;
		cin >> l >> r;
		int ans = numberPrimeFactors[r] - (l == 0?0:numberPrimeFactors[l - 1]);

		if (ans == 0)
			cout << "-1\n";
		else
		{
			vector<int> solution;

			for (int i = l; i <= r; ++i)
			{
				if (numbers[i])
					solution.push_back(i);		
			}

			for (int i = 0; i < solution.size(); ++i)
				cout << solution[i] << (i + 1 == solution.size()?"\n":" ");
		}
	}

	return 0;
}