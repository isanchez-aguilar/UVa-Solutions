/*
*	User: Isanchez_Aguilar
*	Problem: UVA 679 - Dropping Balls
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int ball;
		int height;
		
		cin >> height >> ball;

		int position = 1;
		int currentLevel = 1;

		while (currentLevel + 1 <= height)
		{
			if (ball & 1 != 0)
			{
				position <<= 1;
				ball = (ball >> 1) + 1;
			}
			else
			{
				ball >>= 1;
				position = (position << 1) + 1;
			}

			++currentLevel;
		}

		cout << position << "\n";
	}

	return 0;
}