/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10976 - Fractions Again?!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	while(cin >> k)
	{
		int limit = (k << 1) + 1;
		vector< pair<int, int> > ans(0);
		// Begin with k + 1 because y < k x is negatives and y = k is y * k / 0 and limit is 2 * k  because if y = 2 * k + c then y > x.
		for(int y = k + 1; y < limit; ++y)
		{
			// If the fraction is a integer then x = (y * k) / (y - k). 
			if((y * k) % (y - k) == 0)
				ans.push_back(pair<int,int>((y * k) / (y - k), y));
		}
		// Print fractions.
		int size = ans.size();
		cout << size << '\n';
		for(int i = 0; i < size; ++i)
		{
			cout << "1/" << k << " = 1/" << ans[i].first << " + 1/" << ans[i].second << "\n";
		}
	}
	return 0;
}