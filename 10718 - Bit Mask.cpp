/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10718 - Bit Mask
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	long long l;
	long long u;

	while(cin >> n >> l >> u)
	{
		long long m = 0;
		
		for(int i  = 0; i <= 32; ++i)
		{
			long long on = n & (1LL << (32 - i));

			if(on)
			{
				long long temp = on - 1;
				temp |= m;
				if(temp < l)
					m |= on;
			}
			else
			{
				long long temp = m;
				temp |= (1LL << (32 - i));

				if(temp <= u)
					m = temp;
			}
		}

		cout << m << "\n";
	}

	return 0;
}