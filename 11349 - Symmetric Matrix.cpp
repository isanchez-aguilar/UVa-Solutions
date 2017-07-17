/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11349 - Symmetric Matrix
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
		char temp;
		cin >> temp >> temp >> n;

		bool isSymmetric = 1;
		vector< vector<long long> > matrix(n, vector<long long>(n));

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				cin >> matrix[i][j];

				if(matrix[i][j] < 0)
					isSymmetric = 0;
			}
		}

		if(isSymmetric)
		{
			for(int i = 0; i < n; ++i)
			{
				for(int j = 0; j < n; ++j)
				{
					if(matrix[i][j] != matrix[n - i - 1][n - j - 1])
					{
						isSymmetric = 0;
						break;
					}
				}
			}

			if(isSymmetric)
				cout << "Test #" << t << ": Symmetric.\n";
			else
				cout << "Test #" << t << ": Non-symmetric.\n";	
		}
		else
			cout << "Test #" << t << ": Non-symmetric.\n";
	}

	return 0;
}