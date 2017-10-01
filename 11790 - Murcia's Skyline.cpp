/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11790 - Murcia's Skyline
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		int n;
		cin >> n;

		vector<int> lis(n);
		vector<int> lds(n);
		vector<int> width(n);
		vector<int> height(n);

		for(int i = 0; i < n; ++i)
			cin >> height[i];
		for(int i = 0; i < n; ++i)
			cin >> width[i];

		int maxWidthIncreasing = 0;
		int maxWidthDecreasing = 0;

		for(int i = 0; i < n; ++i)
		{
			int w = width[i];
			lis[i] = w;
			lds[i] = w;

			for(int j = 0; j < i; ++j)
			{
				if(height[j] < height[i])
					lis[i] = max(lis[i], lis[j] + w);
				if(height[i] < height[j])
					lds[i] = max(lds[i], lds[j] + w);
			}

			maxWidthIncreasing = max(maxWidthIncreasing, lis[i]);
			maxWidthDecreasing = max(maxWidthDecreasing, lds[i]);
		}

		if(maxWidthDecreasing <= maxWidthIncreasing)
			cout << "Case " << t << ". Increasing (" << maxWidthIncreasing << "). Decreasing (" << maxWidthDecreasing << ").\n";
		else
			cout << "Case " << t << ". Decreasing (" << maxWidthDecreasing << "). Increasing (" << maxWidthIncreasing << ").\n";
	}

	return 0;
}