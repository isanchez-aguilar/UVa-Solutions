/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11222 - Only I did it!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		int solved[3];
		int problems[3][1000];
		int solvedTimes[10001] = {0};

		for(int i = 0; i < 3; i++)
		{
			cin >> solved[i];
			for(int j = 0; j < solved[i]; j++)
			{
				cin >> problems[i][j];
				++solvedTimes[problems[i][j]];
			}

			sort(problems[i], problems[i] + solved[i]);
		}

		int solve[3];
		int maxSolved = 0;
		
		for(int i = 0; i < 3; i++)
		{
			int noRepeated = 0;
			
			for(int j = 0; j < solved[i]; j++)
			{
				if(solvedTimes[problems[i][j]] == 1)
					++noRepeated;
			}

			solve[i] = noRepeated;
			maxSolved = max(maxSolved, noRepeated);
		}

		cout << "Case #" << t << ":\n";
		for(int i = 0; i < 3; i++)
		{
			if(solve[i] == maxSolved)
			{
				cout << (i + 1) << " " << solve[i];
				for(int j = 0; j < solved[i]; j++)
				{
					if(solvedTimes[problems[i][j]] == 1)
						cout << " " << problems[i][j];
				}
				cout << "\n";
			}
		}
	}
	return 0;
}