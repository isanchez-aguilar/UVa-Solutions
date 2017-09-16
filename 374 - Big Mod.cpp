/*
*	User: Isanchez_Aguilar
*	Problem: UVA 374 - Big Mod
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int b;
	int p;
	int m;

	while(cin >> b >> p >> m)
	{
		b = b % m;
		int mod = 1;

		while(p > 0)
		{
			if(p & 1)
				mod = (mod * b) % m;

			p >>= 1;
			b = (b * b) % m;
		}

		cout << mod << endl;
	}

	return 0;
}