/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10490 - Mr. Azad and his Son!!!!!
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 32769;

long long n;
long long p;
long long f;
bool isNotPrime[MAX];
long long factor[MAX];
vector<long long> prime(1, 2);

inline bool isPrime(long long n)
{
	for (int i = 0; i < prime.size() and prime[i] * prime[i] <= n; ++i)
	{
		if (n % prime[i] == 0)
			return false;
	}

	return true;
}

int main(void)
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

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

	while (cin >> n and n)
	{
		f = (1LL << n) - 1;

		if (isPrime(f))
			cout << "Perfect: " << f * (1 << (n - 1)) << "!\n";
		else if(isPrime(n))
			cout << "Given number is prime. But, NO perfect number is available.\n";
		else
			cout << "Given number is NOT prime! NO perfect number is available.\n";
	}

	return 0;
}