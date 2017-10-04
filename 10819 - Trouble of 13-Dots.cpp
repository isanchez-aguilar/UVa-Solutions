/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10819 - Trouble of 13-Dots
*/
#include <bits/stdc++.h>

using namespace std;

int m;
int n;
pair<int, int> data[101];

inline int getMaximumFavourValue()
{
	int M = m;
	
	if(M > 1800)
		M += 200;

	vector<int> memo(M + 1, 0);

	for(int i = 0; i < n; ++i)
	{
		for(int j = M; j >= data[i].first; --j)
		{
			if(memo[j - data[i].first] > 0 or j == data[i].first)
				memo[j] = max(memo[j], memo[j - data[i].first] + data[i].second);
		}
	}

	if(m >= 1801 and m <= 2000)
	{
		int maxFavourValue = *max_element(memo.begin(), memo.begin() + m);
		
		for(int j = 2001; j <= M; ++j)
			maxFavourValue = max(maxFavourValue, memo[j]);

		return maxFavourValue;
	}
	
	return *max_element(memo.begin(), memo.end());
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> m >> n)
	{
		for(int i = 0; i < n; ++i)
			cin >> data[i].first >> data[i].second;

		cout << getMaximumFavourValue() << "\n";
	}

	return 0;
}