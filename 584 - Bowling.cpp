/*
*	User: Isanchez_Aguilar
*	Problem: UVA 584 - Bowling
*/
#include <bits/stdc++.h>

using namespace std;

string line;

inline int getScore(int i)
{
	if (line[i] == 'X' or line[i + 2] == '/')
		return 10;

	return line[i] + line[i + 2] - ('0' << 1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (getline(cin, line) and line[0] != 'G')
	{
		int i = 0;
		int total = 0;
		int frame = 0;
		
		while (frame != 10)
		{
			int score = getScore(i);

			if (line[i] != 'X')
			{
				if (line[i + 2] == '/')
					score += (line[i + 4] == 'X'?10:line[i + 4] - '0');
				i += 2;
			}
			else
			{
				score += getScore(i + 2);
				if (line[i + 2] == 'X')
					score += (line[i + 4] == 'X'?10:line[i + 4] - '0');
			}

			i += 2;
			++frame;
			total += score;
		}

		cout << total << "\n";
	}

	return 0;
}