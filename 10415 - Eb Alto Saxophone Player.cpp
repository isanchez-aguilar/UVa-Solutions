/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10415 - Eb Alto Saxophone Player
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<char, int> fingers;

	fingers['c'] = 974; // 974 in binary is 1111001110.
	fingers['d'] = 462; // 462 in binary is 0111001110.
	fingers['e'] = 206; // 206 in binary is 0011001110.
	fingers['f'] = 78; // 78 in binary is 0001001110.
	fingers['g'] = 14; // 14 in binary is 0000001110.
	fingers['a'] = 6; // 6 in binary is 0000000110.
	fingers['b'] = 2; // 2 in binary is 0000000010.
	fingers['C'] = 4; // 4 in binary is 0000000100.
	fingers['D'] = 463; // 463 in binary is 0111001111.
	fingers['E'] = 207; // 207 in binary is 0011001111.
	fingers['F'] = 79; // 78 in binary is 0001001111.
	fingers['G'] = 15; // 14 in binary is 0000001111.
	fingers['A'] = 7; // 6 in binary is 0000000111.
	fingers['B'] = 3; // 2 in binary is 0000000011.

	int testCases;
	int fingerFrequency[10];

	cin >> testCases;
	cin.ignore();

	while (testCases--)
	{
		string song;
		getline(cin, song);

		int lastFingers = 0;
		memset(fingerFrequency, 0, sizeof fingerFrequency);

		for (int i = 0; i < song.length(); ++i)
		{
			int currentFingers = fingers[song[i]];
			// Operation per bit to know the new fingers pressed.
			int newFingers = (~lastFingers) & currentFingers;

			// Count the new fingers pressed.
			for (int j = 0, bit = 1; j < 10; ++j, bit <<= 1)
			{
				// Check if the j-th bit is a new finger pressed.
				if ((newFingers & bit) != 0)
					++fingerFrequency[j];
			}

			lastFingers = currentFingers;
		}

		for (int i = 0; i < 10; ++i)
			cout << fingerFrequency[i] << (i + 1 == 10?"\n":" ");
	}

	return 0;
}