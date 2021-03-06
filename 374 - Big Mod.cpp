/*
*	User: Isanchez_Aguilar
*	Problem: UVA 374 - Big Mod
*/
#include <bits/stdc++.h>

using namespace std;

inline int modPow(int a, int p, int m)
{
	a %= m;
	int result = 1;
	
	while (p > 0)
	{
		if (p & 1)
			result = result * a % m;
		
		p >>= 1;
		a = a * a % m;
	}
	
	return result % m;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	int p;
	int m;
	
	while (cin >> a >> m >> p)
		cout << modPow(a, m, p) << "\n";
	

	return 0;
}
