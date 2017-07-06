/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11417 - GCD
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// __gcd is a function of C++11 
	int n;
	while(cin >> n && n)
	{
		int g = 0;
		for(int i = 1; i < n; ++i)
		{
			for(int j = i + 1; j <= n; ++j)
				g += __gcd(i, j);
		}
		cout << g << "\n"; 
	}

	return 0;
}