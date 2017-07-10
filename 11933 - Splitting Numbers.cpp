/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11933 - Splitting Numbers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n && n)
	{
		int a = 0;
		int i = 0;
		int exp = 0;
		int temp = n;
		
		while(temp)
		{
			if(temp & 1)
			{
				++i;
				if(i & 1)
					a += (1 << exp);
			}
			++exp;
			temp >>= 1;
		}

		cout << a << " " << n - a << "\n";
	}

	return 0;
}