/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11040 - Add bricks in the wall
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	int pyramid[10][10];

	cin >> testCases;
	while(testCases--)
	{
		for(int i = 0; i < 9; i += 2)
		{

			for(int j = 0; j <= i; j += 2)
				cin >> pyramid[i][j];
		}

		for(int i = 8; i > 0; i -= 2)
		{
			for(int j = 0; j < i;  j += 2)
			{
				pyramid[i][j + 1] = (pyramid[i - 2][j] - pyramid[i][j] - pyramid[i][j + 2]) >> 1;  
				pyramid[i - 1][j] = pyramid[i][j] + pyramid[i][j + 1];
				pyramid[i - 1][j + 1] = pyramid[i][j + 1] + pyramid[i][j + 2];
			}
		}

		for(int i = 0; i < 9; ++i)
		{
			for(int j = 0; j <= i; ++j)
			{
				cout << pyramid[i][j];
				if(j < i)
					cout << " ";
			}
			cout << endl;
		}

	}

	return 0;
}