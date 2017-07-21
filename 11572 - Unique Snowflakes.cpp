/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11572 - Unique Snowflakes
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
		int bags;
		int length = 0;
		int maxPackage = 0;
		int repeatedPackage = 0;
		map<int, int> snowflakes;

		cin >> bags;

		for(int i = 1; i <= bags; ++i)
		{
			int n;
			cin >> n;
			int seen = snowflakes[n];
			
			if(seen)
			{
				repeatedPackage = max(repeatedPackage, seen);
				length = i - repeatedPackage -1 ;
			}

			++length;
			snowflakes[n] = i;
			maxPackage = max(maxPackage, length);
		}


		cout << maxPackage << "\n";
	}

	return 0;
}