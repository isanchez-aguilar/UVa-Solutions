/*
*	User: Isanchez_Aguilar
*	Problem: UVA 927 - Integer Sequences from Addition of Terms
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c[21];
	int testCases;
	
	cin >> testCases;

	while(testCases--)
	{

		int n;
		cin >> n;
		
		++n;
		for(int i = 0; i < n; ++i)
			cin >> c[i];

		int d;
		int k;
		cin >> d >> k;

		long long x = 1;
		long long ans = 0;
		long long current = 0;

		while(current < k)
		{
			current += x * d;
			
			if(k <= current)
			{		
				ans = 0;
				
				for(int i = 0; i < n; ++i)
					ans += c[i] * pow(x, i);
			}
			++x;
		}

		cout << ans << endl;
	}

	return 0;
}