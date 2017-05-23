/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10139 - Factovisors
*/
#include <bits/stdc++.h>

// Square root of 2^31. 
#define MAX 46342

using namespace std;

// Function to get the power of prime p on q factorial.
int exponent(int p, int q)
{
	int power = 0;
	// While p is not equal to 0 increase power.
	while(p / q)
	{
		power += p / q;
		p /= q;
	}
	return power;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m;
	vector<bool> sieve(MAX, 1);
	vector<int> primes(0);
	// Compute the sieve of primes.
	for(int i = 2; i < MAX; ++i)
	{
		if(sieve[i])
		{
			// Add prime to vector of primes.
			primes.push_back(i);
			// Set false to multiples of the prime i.
			for(int j = i + i; j < MAX; j += i)
				sieve[j] = 0;
		}
	}
	// While not EOF.
	while(cin >> n >> m)
	{
		int p = n;
		int q = m;
		int i = 1;
		int isPrime = 1;
		int currentPrime = 2;
		int raiz = sqrt(q) + 1;
		vector< pair<int, int> > factors(0);
		// While currentPrime is not equal to square root of q.
		while(currentPrime < raiz && q != 1)
		{
			// If currentPrimes is divisor of q then add the currentPrime.
			if(q % currentPrime == 0)
			{
				isPrime = 0;
				q /= currentPrime;
				factors.push_back(pair<int, int>(currentPrime, 1));
			}
			// Get the index of the current prime.
			int j = factors.size() - 1;
			// While the currentPrime divides to q.
			while(q % currentPrime == 0)
			{
				// Get the next number.
				q /= currentPrime;
				// Increase the power of prime.
				++factors[j].second;
			}
			// Get the next prime.
			currentPrime = primes[i++];
		}
		// If the current q is not equal to 1 then is a prime and add to factors.
		if(q != 1)
			factors.push_back(pair<int, int>(q, 1));
		// Assume that q divides to p!.
		int isDivisible = 1;
		// Check the factors of q.
		for(int i = 0; i < factors.size() && isDivisible; ++i)
		{
			// If the power of current prime on q is bigger than q then q does not divide to p.
			if(factors[i].second > exponent(n, factors[i].first))
				isDivisible = 0;
		}
		// If is divisible then print a message.
		if(isDivisible)
			cout << m << " divides " << n << "!\n";
		else
			cout << m << " does not divide " << n << "!\n";

	}
	return 0;
}