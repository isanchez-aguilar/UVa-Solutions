/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12405 - Scarecrow
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
		int length;
		string grid;

		cin >> length >> grid;

		int scarecrows = 0;
		for(int i = 0; i < length; ++i)
		{
			if(grid[i] == '#')
				continue;
			
			i += 2;
			++scarecrows;
		}

		cout << "Case " << t << ": " << scarecrows << "\n";
	}

	return 0;
}