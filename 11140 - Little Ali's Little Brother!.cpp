/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11140 - Little Ali's Little Brother!
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
		int pieces;
		int imageWidth;
		int imageHeight;

		cin >> imageHeight >> imageWidth >> pieces;

		char puzzle[imageHeight][imageWidth + 1];

		for (int i = 0; i < imageHeight; ++i)
			cin >> puzzle[i];
		
		while (pieces--)
		{
			int width;
			int height;
			cin >> height >> width;
	
			char piece[height][width + 1];
			
			for (int i = 0; i < height; ++i)
				cin >> piece[i];

			bool noFit = true;
			
			for (int i = -imageHeight; i < imageHeight and noFit; ++i)
			{
				for (int j = -imageWidth; j < imageWidth; ++j)
				{
					noFit = false;

					for (int k = 0; k < height and not noFit; ++k)
					{
						for (int l = 0; l < width; ++l)
						{
							int x = k + i;
							int y = l + j;

							if (piece[k][l] == '.')
								continue;

							if (x < 0 or x >= imageHeight or y < 0 or y >= imageWidth)
							{
								k = height;
								noFit = true;
								break;
							}

							if (puzzle[x][y] == '.')
							{
								noFit = true;
								break;
							}
						}
					}

					if (not noFit)
						break;

				}
			}

			if (noFit)
				cout << "No\n";
			else
				cout << "Yes\n";
		}

		cout << "\n";
	}

	return 0;
}