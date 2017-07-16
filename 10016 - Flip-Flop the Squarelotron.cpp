/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10016 - Flip-Flop the Squarelotron
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
		vector< vector<int> > matrix(n, vector<int>(n));
		
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				cin >> matrix[i][j];
		}

		int rings = (n >> 1) + (n & 1);
		for(int i = 0; i < rings; ++i)
		{
			int actions;
			cin >> actions;
			for(int j = 0; j < actions; ++j)
			{
				int action;
				cin >> action;
				int limit = n - i - 1;
				switch(action)
				{
					// Upside-Down Flip
					case 1:
						for(int k = i; k <= limit; ++k)
							swap(matrix[i][k], matrix[limit][k]);
						
						for(int k = i + 1; (k << 1) < n - 1; ++k)
						{
							int l = n - k - 1;
							swap(matrix[k][i], matrix[l][i]);
							swap(matrix[k][limit], matrix[l][limit]);
						}
					break;
					// Left-Right Flip
					case 2:
						for(int k = i; k <= limit; ++k)
							swap(matrix[k][i], matrix[k][limit]);
						
						for(int k = i + 1; (k << 1) < n - 1; ++k)
						{
							int l = n - k - 1;
							swap(matrix[i][k], matrix[i][l]);
							swap(matrix[limit][k], matrix[limit][l]);
						}
					break;
					// Flip through the Main Diagonal
					case 3:
						for(int k = i + 1; k <= limit; ++k)
						{
							swap(matrix[i][k], matrix[k][i]);
							swap(matrix[limit][k], matrix[k][limit]);
						}
					break;
					// Flip through the Main Inverse Diagonal
					case 4:
						for(int k = limit - 1, l = i + 1; k >= i; --k, ++l)
						{
							swap(matrix[i][k], matrix[l][limit]);
							swap(matrix[l][i], matrix[limit][k]);
						}
					break;
				}
			}
		}

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				cout << matrix[i][j] << (j + 1 < n?" ":"\n");
		}
	}

	return 0;
}