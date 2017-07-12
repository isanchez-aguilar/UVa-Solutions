/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11150 - Cola
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n)
	{
		int borrowed = 0;
		int bottles = n; 
		while(3 <= n)
		{
			bottles += n / 3;
			n = n / 3 + n % 3;
		}
		if(n == 2)
			++bottles;
		cout << bottles << "\n";
	}
	return 0;
}