/*
*	User: Isanchez_Aguilar
*	Problem: UVA 594 - One Little, Two Little, Three Little Endians
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n)
	{
		int nConverted = 0;
		for (int i = 0; i < 4; ++i)
		{
			nConverted <<= 8;
			nConverted |= ((n >> (i << 3)) & 255); 
		}

		cout << n << " converts to " << nConverted << "\n";
	}

	return 0;
}