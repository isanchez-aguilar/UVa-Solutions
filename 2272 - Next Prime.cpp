/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11287 - Pseudoprime Numbers
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 99992;

long long n;
long long p;
long long j;
long long* iPtr;
int primeSize = 0;
bool isNotPrime[MAX];
long long prime[9522];
//vector<long long> prime(1, 2);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	prime[primeSize++] = 2;

	for (int i = 4; i < MAX; i += 2)
		isNotPrime[i] = true;
	
	for (p = 3; p < MAX; p += 2)
	{
		if (not isNotPrime[p])
		{
			for (j = p * p; j < MAX; j += p)
				isNotPrime[j] = true;

			prime[primeSize++] = p;
			//prime.push_back(i);
		}
	}

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		cin >> n;

		iPtr = lower_bound(prime, prime + primeSize, n);
		
		if (iPtr != prime + primeSize)
			cout << *iPtr << endl;
		else
		{
			bool found = false;

			for (p = n; not found; ++p)
			{
				bool isPrime = true;
				
				for (int j = 0; j < primeSize and prime[j] * prime[j] <= p; ++j)
				{
					if (p % prime[j] == 0)
					{
						isPrime = false;
						break;
					}
				}
				
				if (isPrime)
				{
					found = true;
					cout << p << "\n";
					
					break;
				}
			}
		}
	}

	return 0;
}