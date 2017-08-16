/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1260 - Sales
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int n;

		cin >> n;
		vector<int> data(n);

		for(int i = 0; i < n; ++i)
			cin >> data[i];

		int sum = 0;
		for(int i = 1; i < n; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(data[j] <= data[i])
					++sum;
			}
		}

		cout << sum << endl;
	}

	return 0;
}