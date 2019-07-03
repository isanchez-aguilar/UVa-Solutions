/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10127 - Ones
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

	int n;
	
	while (cin >> n)
	{
		int digits = 0;
		int currentMod = 0;
			
		do
		{
			++digits;
			//cout << currentMod << " ";
			currentMod = ((currentMod * 10 % n) + 1) % n; 
			//cout << currentMod << endl;
		}while (currentMod > 0);
		
		cout << digits << "\n";
	}

	return 0;
}
