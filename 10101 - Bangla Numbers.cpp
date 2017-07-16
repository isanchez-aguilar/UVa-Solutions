/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10101 - Bangla Numbers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	long long n;
	
	while(cin >> n)
	{
		cout << setw(4) << t++ << ".";
		if(!n)
			cout << " 0\n";
		else
		{
			if(n / 100000000000000LL)
			{
				cout << " " << n / 100000000000000LL << " kuti";
				n %= 100000000000000LL;
				if(n < 10000000LL)
					cout << " kuti";
			}
			if(n / 1000000000000LL)
			{
				cout << " " << n / 1000000000000LL << " lakh";
				n %= 1000000000000LL;
				if(n < 10000000LL)
					cout << " kuti";
			}
			if(n / 10000000000LL)
			{
				cout << " " << n / 10000000000LL << " hajar";
				n %= 10000000000LL;
				 if(n < 10000000LL)
				 	cout << " kuti";
			}
			if(n / 1000000000LL)
			{
				cout << " " << n / 1000000000LL << " shata";
				n %= 1000000000LL;
					if(n < 10000000)
						cout << " kuti";
			}
			if(n / 10000000LL)
			{
				cout << " " << n / 10000000LL << " kuti";
				n %= 10000000LL;
			}
			if(n / 100000LL)
			{
				cout << " " << n / 100000LL << " lakh";
				n %= 100000LL;
			}
			if(n / 1000LL)
			{
				cout << " " << n / 1000LL << " hajar";
				n %= 1000LL;
			}
			if(n / 100LL)
			{
				cout << " " << n / 100LL << " shata";
				n %= 100LL;	
			}
			if(n)
				cout << " " << n;
			cout << "\n";
		}
	}

	return 0;
}