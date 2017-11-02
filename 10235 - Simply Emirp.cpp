/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10235 - Simply Emirp
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	bitset<1000001> emirp;
	bitset<1000001> prime;
	bitset<1000001> checked;

	while(cin >> n)
	{
		if(checked[n])
		{
			if(prime[n])
				cout << n << " is " << (emirp[n]?"emirp.\n":"prime.\n");
			else
				cout << n << " is not prime.\n";

			continue;
		}

		checked[n] = true;
		bool isPrime = true;
		int squareroot = round(sqrt(n));
		
		for(int i = 2; i <= squareroot; ++i)
		{
			if(n % i == 0)
			{
				isPrime = false;
				break;
			}
		}

		prime[n] = isPrime;

		if(isPrime)
		{
			ostringstream out;
			out << n;
			
			string s = out.str();
			reverse(s.begin(), s.end());

			istringstream in(s);
			
			int m;
			in >> m;
			
			if(m == n)
				emirp[n] = false;

			else if(not checked[m])
			{
				isPrime = true;
				checked[m] = true;
				int squareroot = round(sqrt(m));
				
				for(int i = 2; i <= squareroot; ++i)
				{
					if(m % i == 0)
					{
						isPrime = false;
						break;
					}
				}

				prime[m] = isPrime;
				emirp[n] = isPrime;
				emirp[m] = isPrime;
			}
			
			cout << n << " is " << (emirp[m]?"emirp.\n":"prime.\n");
		}
		else
			cout << n << " is not prime.\n";
	}

	return 0;
}