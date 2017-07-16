/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10703 - Free spots
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int width;
	int height;
	int subRectangles;
	while(cin >> width >> height >> subRectangles && (width || height || subRectangles))
	{
		int emptySpots = width * height;
		vector< vector<bool> > board(height, vector<bool>(width, false));

		for(int i = 0; i < subRectangles; ++i)
		{
			int x1;
			int x2;
			int y1;
			int y2;
			cin >> x1 >> y1 >> x2 >> y2;

			int minX = min(x1, x2) - 1;
			int minY = min(y1, y2) - 1;
			int maxX = max(x1, x2);
			int maxY = max(y1, y2);

			for(int k = minY; k < maxY; ++k)
			{
				for(int j = minX; j < maxX; ++j)
				{
					if(!board[k][j])
					{
						--emptySpots;
						board[k][j] = 1;
					}
				}
			}
		}
		if(!emptySpots)
			cout << "There is no empty spots.\n";
		else
		{
			if(emptySpots == 1)
				cout << "There is one empty spot.\n";
			else
				cout << "There are " << emptySpots << " empty spots.\n";
		}

	}

	return 0;
}