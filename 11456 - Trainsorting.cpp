/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11456 - Trainsorting
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
		
		vector<int> lis(n);
		vector<int> lds(n);
		vector<int> weight(n);

		for(int i = 0; i < n; ++i)
			cin >> weight[i];

		for(int i = n - 1; i >= 0; --i)
		{
			lis[i] = 1;
			lds[i] = 1;
			for(int j = i + 1; j < n; ++j)
			{
				if(weight[i] < weight[j])
					lis[i] = max(lis[j] + 1, lis[i]);
				else if(weight[i] > weight[j])
					lds[i] = max(lds[j] + 1, lds[i]);	
			}
		}

		int LDS = 0;
		for(int i = 0; i < n; ++i)
			LDS = max(LDS, lis[i] + lds[i] - 1);

		cout << LDS << "\n";
	}

	return 0;
}