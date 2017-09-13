/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12192 - Grapevine
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	int number[500][500];

	while(cin >> n >> m and (n or m))
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
				cin >> number[i][j];
		}

		int q;
		cin >> q;

		while(q--)
		{
			int a;
			int b;
			cin >> a >> b;

			int maxSize = 0;	
			for(int i = 0; i < n; ++i)
			{
				int minPosition = lower_bound(number[i], number[i] + m, a) - number[i];
				
				for(int j = maxSize; j < n; ++j)
				{
					if(n <= i + j or m <= minPosition + j or b < number[i + j][minPosition + j])
						break;
					
					maxSize = max(maxSize, j + 1);
				}

			}

			cout << maxSize << "\n";
		}
		cout << "-\n";
	}

	return 0;	
}