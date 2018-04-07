/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11254 - Consecutive Integers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int endSum;
	int startSum;
	
	while (cin >> n and n != -1)
	{
		int n2 = n << 1;
		int limit = sqrt(n2);

		for (int r = limit; r > -1; --r)
		{
			int a = (n2 + r * (1 - r)) / (r << 1);
			
			int sum = ((a << 1) + r - 1) * r;
			
			if (sum == n2)
			{
				startSum = a;
				endSum = a + r - 1;
				break;
			}
		}

		cout << n << " = " << startSum << " + ... + " << endSum << "\n";
	}

	return 0;
}