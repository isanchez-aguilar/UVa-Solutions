/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10958 - How Many Solutions?
*/
#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

vector<int> prime;

inline int getNumberOfDivisors(long long n)
{
	int index = 0;
	int divisors = 1;
	int primeFactors = prime[0];

	while (primeFactors * primeFactors <= n)
	{
		int power = 0;
		
		while (n % primeFactors == 0)
		{
			++power; 
			n /= primeFactors;
		}
		
		divisors *= (power + 1);

		primeFactors = prime[++index];
	}

	if (n != 1)
		divisors <<= 1;

	return divisors;
}

void sieve()
{
	bitset<MAX> isNotPrime;

	for (int i = 2; i < MAX; ++i)
	{
		if (not isNotPrime[i])
		{
			prime.push_back(i);

			for (int j = (i << 1); j < MAX; j += i)
				isNotPrime[j] = true;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	long long m;
	long long n;
	long long p;

	sieve();

	while (cin >> m >> n >> p and m and n and p)
		cout << "Case " << ++t << ": " << ((getNumberOfDivisors(abs(m * n * p * p)) << 1) - 1) << "\n";

	return 0;
}