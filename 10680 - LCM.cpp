/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10680 - LCM
*/
#include <bits/stdc++.h>

#define MAX 1000256

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

inline int getMaxExp(int n, int &p)
{
	int exp = 0;
	while(n / p)
	{
		++exp;
		n /= p;
	}
	return exp;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vi sieve(1, 2);
	bitset<MAX> noPrime;

	noPrime[0] = 1;
	noPrime[1] = 1;
	for(int i = 4; i < MAX; i += 2)
		noPrime[i] = 1;

	for(int i = 3; i < MAX; i += 2)
	{
		if(!noPrime[i])
		{
			sieve.push_back(i);
			for(int j = i + i; j < MAX; j += i)
				noPrime[j] = 1;
		}
	}

	int n;
	while(cin >> n && n)
	{
		if(n == 1)
			cout << "1\n";
		else
		{
			int i = 0;
			vpi factors;	
			int prime = sieve[0];
			int exp = getMaxExp(n, prime);
			while(exp)
			{
 				factors.push_back(pi(prime, exp));
				prime = sieve[++i];
				exp = getMaxExp(n, prime);
			}
			if(n >= 5)
			{
				factors[0].second -= factors[2].second;
				factors[2].second = 0;
			}
		
			int digit = 1;
			int size = factors.size();

			for(int i = 0; i < size; ++i)
			{
				int exp = factors[i].second;
				int prime = factors[i].first;
				for(int j = 0; j < exp; ++j)
				{
					digit = (digit * prime) % 10;
				}
			}
			
			cout << digit << "\n";
		}
	}

	return 0;
}