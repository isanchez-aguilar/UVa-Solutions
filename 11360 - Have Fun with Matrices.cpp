/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11360 - Have Fun with Matrices
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
		vector< vector<int> > aT(n, vector<int>(n));
		vector< vector<int> > matrix(n, vector<int>(n));

		for(int i = 0; i < n; ++i)
		{
			string row;
			cin >> row;
			for(int j = 0; j < n; ++j)
				matrix[i][j] = row[j] - '0';
		}

		int instructions;
		cin >> instructions;

		for(int k = 0; k < instructions; ++k)
		{
			int a;
			int b;
			string instruction;

			cin >> instruction;
			switch(instruction[0])
			{
				case 't':
					for(int i = 0; i < n; ++i)
					{
						for(int j = 0; j < n; ++j)
							aT[j][i] = matrix[i][j];
					}
					matrix = aT;
				break;
				case 'r':
					cin >> a >> b;
					matrix[a - 1].swap(matrix[b - 1]);
				break;
				case 'c':
					int a;
					int b;
					cin >> a >> b;
					--a;
					--b;
					for(int i = 0; i < n; ++i)
						swap(matrix[i][a], matrix[i][b]);	
				break;
				case 'i':
					for(int i = 0; i < n; ++i)
					{
						for(int j = 0; j < n; ++j)
							matrix[i][j] = (matrix[i][j] + 1) % 10;
					}
				break;
				default:
					for(int i = 0; i < n; ++i)
					{
						for(int j = 0; j < n; ++j)
						{
							--matrix[i][j];
							if(matrix[i][j] < 0)
								matrix[i][j] = 9;
						}
					}
			}
		}
		if(t - 1 > 0)
			cout << "\n";
		cout << "Case #" << t << "\n";
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				cout << matrix[i][j];
			cout << "\n";
		}
	}
	cout << "\n";
	return 0;
}