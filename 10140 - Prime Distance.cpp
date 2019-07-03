/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10140 - Prime Distance
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 47000;

long long l;
long long r;
long long n;
long long p;
long long p1;
long long p2;
long long p3;
long long p4;
bool isNotPrime[MAX];
long long factor[MAX];
long long previousPrime;
vector<long long> prime(1, 2);
bitset<1000001> isNotPrimeInterval;

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

	while (cin >> l >> r)
	{
		isNotPrimeInterval.reset();

		if (l == 1)
			isNotPrimeInterval.set(0);


		for (int i = 0; i < prime.size() and prime[i] * prime[i] <= r; ++i)
		{
			p = (l % prime[i] == 0?l:l + (prime[i] - l % prime[i]));

			while (p <= r)
			{
				if (p != prime[i])
					isNotPrimeInterval.set(p - l);
				
				p += prime[i];
			}
		}

		p3 = 0;
		p4 = 0;
		p2 = r;
		p1 = -1;
		previousPrime = -1;

		for (p = l; p <= r; ++p)
		{
			if (not isNotPrimeInterval[p - l])
			{
				if (previousPrime != -1)
				{
					if (p - previousPrime < p2 - p1)
					{
						p2 = p;
						p1 = previousPrime;
					}

					if (p4 - p3 < p - previousPrime)
					{
						p4 = p;
						p3 = previousPrime;
					}

				}				
				
				previousPrime = p;
			}
		}

		if (p1 == -1)
			cout << "There are no adjacent primes.\n";
		else
			cout << p1 << "," << p2 << " are closest, " << p3 << "," << p4 << " are most distant.\n";
	}

	return 0;
}