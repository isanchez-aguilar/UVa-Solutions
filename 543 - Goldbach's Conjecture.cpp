/*
*	User: Isanchez_Aguilar
*	Problem: UVA 543 - Goldbach's Conjecture
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

bool isNotPrime[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> prime(1, 2);


	for (int i = 4; i < MAX; i += 2)
		isNotPrime[i] = true;
	
	for (long long i = 3; i < MAX; i += 2)
	{
		if (not isNotPrime[i])
		{
			for (long long j = i * i; j < MAX; j += i)
				isNotPrime[j] = true;

			prime.push_back(i);
		}
	}

	int n;
	while (cin >> n and n)
	{
		int l = 0;
		int a = -1;
		int b = -1;
		int r = prime.size() - 1;
		
		while (l <= r)
		{
			int sum = prime[l] + prime[r];

			if (sum == n)
			{
				a = prime[l];
				b = prime[r];

				break;
			}

			if (sum < n)
				++l;
			else
				--r;
		}

		if (a == -1)
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << n << " = " << a << " + " << b << "\n";
	}

	return 0;
}