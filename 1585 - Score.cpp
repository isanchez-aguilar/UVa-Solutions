/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1585 - Score
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
		string test;
		cin >> test;

		int score = 0;
		int extra = 0;
		int length = test.length();

		for(int i = 0; i < length; ++i)
		{
			// If It is a good answer then increase the score and consecutive points(extra).
			if(test[i] == 'O')
			{
				score += extra + 1; 
				++extra;
			}
			else
				extra = 0;
		}
		cout << score << "\n";
	}

	return 0;
}