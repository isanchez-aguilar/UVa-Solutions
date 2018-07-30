/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11588 - Image Coding
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	int frequency[26];
	char image[20][20];

	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		int width;
		int height;
		int mostImportant;
		int leastImportant;
		cin >> height >> width >> mostImportant >> leastImportant;

		for (int i = 0; i < height; ++i)
			cin >> image[i];

		memset(frequency, 0, sizeof frequency);

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
				++frequency[image[i][j] - 'A'];
		}

		sort(frequency, frequency + 26);

		int mostFrequent = 1;
		int totalPixels = height * width;

		for (int i = 24; i >= 0 and frequency[25] == frequency[i]; --i)
			++mostFrequent;

		int bytes = (totalPixels - frequency[25] * mostFrequent) * leastImportant + mostFrequent * frequency[25] * mostImportant;
		
		cout << "Case " << t << ": " << bytes << "\n";
	}

	return 0;
}