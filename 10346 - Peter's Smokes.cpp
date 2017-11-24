/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10346 - Peter's Smokes
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int k;
	while(cin >> n >> k)
	{
		int total = 0;
		int bullet = 0;

		while(n)
		{
			total += n;
			bullet += n;
			n = bullet / k;
			bullet %= k; 
		}

		cout << total << "\n";
	}

	return 0;
}