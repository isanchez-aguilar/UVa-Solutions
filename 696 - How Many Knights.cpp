/*
*	User: Isanchez_Aguilar
*	Problem: UVA 696 - How Many Knights
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m;
	int p;
	int q;
	int knights;
	// Read while n or m is not equal to 0.
	while(cin >> n >> m && n || m)
	{
		// If m is lesser than n swap on auxiliary variables.
		if(m < n)
		{
			p = m;
			q = n;
		}
		else
		{
			p = n;
			q = m;
		}
		// If the minimum size is 1 then set the maximum size as the number of knights.
		if(p == 1)
			knights = q;
		// If the minimum size is 2 then compute the knigths and add the residue,
		else if(p == 2)
			knights = q / 4 * 4 + (q % 4 > 2? 4: q % 4 * 2);
		// If m and n is bigger than 2 then compute with classic formula.
		else
			knights = (p * q + 1) / 2;
		// Print the data of test case.
		cout << knights << " knights may be placed on a " << n << " row " << m << " column board.\n";
	}
	return 0;
}