/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11057 - Exact Sum
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
		vector<int> number(n);
		
		for(int i = 0; i < n; ++i)
			cin >> number[i];

		sort(number.begin(), number.end());

		int s;
		cin >> s;

		int a;
		int b;
		int middle = s >> 1;
		int minDifference = s;
		
		for(int i = 0; number[i] <= middle and i < n; ++i)
		{
			int k = s - number[i];
			vector<int>::iterator j = lower_bound(number.begin(), number.end(), k);

			if(j != number.end() and (int)(j - number.begin()) != i and *j == k and abs(number[i] - k) < minDifference)
			{
				b = k;
				a = number[i];
				minDifference = abs(a - b);
			}
		}

		cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
	}

	return 0;
}