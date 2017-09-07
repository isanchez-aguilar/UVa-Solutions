/*
*	User: Isanchez_Aguilar
*	Problem: UVA 524 - Prime Ring Problem
*/
#include <bits/stdc++.h>

#define MAX 32

using namespace std;

int n;
int ring[17];
bitset<MAX> used;
bitset<MAX> isPrime;

inline void createSieve()
{
	for(int i = 0; i < MAX; ++i)
	{
		if(i & 1)
			isPrime[i] = true;
	}

	isPrime[2] = true;
	
	for(int i = 3; i < MAX; i += 2)
	{
		if(isPrime[i])
		{
			for(int j = i << 1; j < MAX; j += i)
				isPrime[j] = false;
		}	
	}

	return;
}

inline void searchRings(int index)
{
	if(index == n - 1 and isPrime[ring[index] + ring[n]])
	{
		for(int i = 0; i < n; ++i)
			cout << ring[i] << (i + 1 == n?"\n":" ");

		return;
	}

	for(int i = 2; i <= n; ++i)
	{
		if(not used[i] and isPrime[ring[index] + i])
		{
			used[i] = true;
			ring[index + 1] = i;

			searchRings(index + 1);
			
			used[i] = false;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	createSieve();

	while(cin >> n)
	{
		if(t++)
			cout << "\n";
		cout << "Case " << t << ":\n";

		ring[0] = 1;
		ring[n] = 1;

		searchRings(0);
	}


	return 0;
}