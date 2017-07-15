/*
*	User: Isanchez_Aguilar
*	Problem: UVA 541 - Error Correction
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector< bitset<100> > matrix(100);
	while(cin >> n && n)
	{
		int oddRow = -1;
		bool corrupt = 0;
		for(int i = 0; i < n; ++i)
		{
			int sum = 0;
			for(int j = 0; j < n; ++j)
			{
				int value;
				cin >> value;
				matrix[i][j] = value;
				sum += value;
			}
			if(sum & 1)
			{
				if(oddRow == -1)
					oddRow = i;
				else
					corrupt = 1;
			}
		}
		if(corrupt)
			cout << "Corrupt\n";
		else
		{
			int oddColumn = -1;
			for(int j = 0; j < n; ++j)
			{
				int sum = 0;
				for(int i = 0; i < n; ++i)
					sum += matrix[i][j];
				if(sum & 1)
				{
					if(oddColumn == -1)
						oddColumn = j;
					else
					{
						corrupt = 1;
						break;
					}
				}
			}

			if(corrupt)
				cout << "Corrupt\n";
			else if(oddColumn == -1 && oddRow == -1)
				cout << "OK\n";
			else
				cout << "Change bit (" << (oddRow + 1) << "," << (oddColumn + 1) << ")\n"; 
		}
	}

	return 0;
}