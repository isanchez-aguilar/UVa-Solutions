/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11287 - Pseudoprime Numbers
*/
#include <bits/stdc++.h>

using namespace std;

inline long long modPow(long long a, long long p, long long m)
{
	a %= m;
	long long result = 1;

	while (p > 0)
	{
		if (p & 1)
			result = result * a % m;

		a = a * a % m;
		p >>= 1;
	}

	return result % m;
}

inline bool isPrime(long long n)
{
	long long sqrtN = sqrt(n);

	for (long long i = 2; i <= sqrtN; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long p;
	long long a;
	while (cin >> p >> a and (p or a))
	{
		if (a == modPow(a, p, p) and not isPrime(p))
			cout << "yes\n";
		else
			cout << "no\n";
	}
	
	return 0;
}