/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12542 - Prime Substring
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

bool isNotPrime[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<string, bool> isPrime;

	isPrime["2"] = true;

	for (int i = 4; i < MAX; i += 2)
		isNotPrime[i] = true;
	
	for (long long i = 3; i < MAX; i += 2)
	{
		if (not isNotPrime[i])
		{
			for (long long j = i * i; j < MAX; j += i)
			{
				isNotPrime[j] = true;
			}

			isPrime[to_string(i)] = true;
		}
	}

	string n;
	while (cin >> n and n != "0")
	{
		string maxPrime = "0";

		for (int digits = 5; digits > 0; --digits)
		{
			for (int i = 0; i + digits - 1 < n.length(); ++i)
			{
				string number = n.substr(i, digits);
				
				if (isPrime[number])
					maxPrime = max(maxPrime, number);
			}

			if (maxPrime != "0")
				break;
		}

		cout << maxPrime << "\n";
	}

	return 0;
}