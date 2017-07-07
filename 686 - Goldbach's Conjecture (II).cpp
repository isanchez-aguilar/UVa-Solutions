/*
*	User: Isanchez_Aguilar
*	Problem: UVA 686 - Goldbach's Conjecture (II)
*/
#include <bits/stdc++.h>

#define MAX 32767

using namespace std;

typedef vector<int> vi;
typedef bitset<MAX> vb;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vb noPrime;
	vi sieve(1, 2);
	noPrime[0] = 1;
	noPrime[1] = 1;
	// Sieve of primes.
	for(int i = 4; i < MAX; i += 2)
		noPrime[i] = 1;

	for(int i = 3; i < MAX; i += 2)
	{
		if(!noPrime[i])
		{
			for(int j = i * i; j < MAX; j += i)
				noPrime[j] = 1;
			sieve.push_back(i);
		}
	}

	int n;
	while(cin >> n && n)
	{
		int sums = 0;
		int half = n >> 1;
		// Compute pairs of prime numbers up to half.
		for(int i = 0; sieve[i] <= half; ++i)
		{
			int rest = n - sieve[i];
			if(!noPrime[rest])
				++sums;
		}
		// Print number of pairs of primes.
		cout << sums << endl;
	}

	return 0;
}