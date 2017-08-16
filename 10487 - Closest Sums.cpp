/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10487 - Closest Sums
*/
#include <bits/stdc++.h>

using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;

	while(cin >> n && n)
	{
		vector<int> numbers(n);

		for(int i = 0; i < n; ++i)
			cin >> numbers[i];

		int k = 0;
		int length = (n - 1) * n >> 1;
		
		vector<int> sum(length);
		for(int i = 0; i < n; ++i)
		{
			for(int j = i + 1; j < n; ++j)
				sum[k++] = (numbers [i] + numbers [j]);
		}

		int q;
		cin >> q;

		cout << "Case " << ++t << ":\n";
		for(int i = 0; i < q; ++i)
		{
			int k;
			int bestSum;
			int minDifference = INT_MAX;
			
			cin >> k;
			for(int j = 0; j < length; ++j)
			{
				int difference = abs(k - sum [j]);
				
				if(difference < minDifference)
				{
					bestSum = sum [j];
					minDifference = difference;
				}
			}
			cout << "Closest sum to " << k << " is " << bestSum << ".\n";
		}
	}

	return 0;
}