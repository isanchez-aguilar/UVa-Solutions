/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10940 - Throwing cards away II
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n and n)
	{
		int k = 0;
		int currentProduct = 1;
		
		while ((currentProduct << 1) < n)
		{
			++k;
			currentProduct <<= 1;
		}

		int difference = n - (1 << k);

		if (difference == 0)
			cout << (1 << k) << "\n";
		else
			cout << (difference << 1) << "\n";
	}
}