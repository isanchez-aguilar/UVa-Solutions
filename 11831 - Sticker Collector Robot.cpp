/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11831 - Sticker Collector Robot
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int width;
	int height;
	char grid[100][100];
	int numberInstruction;
	const int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	while(cin >> height >> width >> numberInstruction and (width or height or numberInstruction))
	{
		int move;
		int xi = -1;
		int yi = -1;

		for(int i = 0; i < height; ++i)
		{
			for(int j = 0; j < width; ++j)
			{
				cin >> grid[i][j];
				
				if(xi == -1 and grid[i][j] != '.' and grid[i][j] != '#' and grid[i][j] != '*')
				{
					yi = i;
					xi = j;

					switch(grid[i][j])
					{
						case 'N':
							move = 0; 
						break;
						case 'L':
							move = 1; 
						break;
						case 'S':
							move = 2; 
						break;
						default:
							move = 3; 
						break;
					}
				}
			}
		}

		char c;
		cin.ignore();
		int stickers = 0;
		while((c = cin.get()) != '\n')
		{
			switch(c)
			{
				case 'D':
					move = (move + 1) % 4;
				break;
				case 'E':
					move = (move - 1) % 4;
					
					if(move < 0)
						move += 4;
				break;
				default:
					int y = moves[move][0] + yi;
					int x = moves[move][1] + xi;

					if(x < width and x >= 0 and y < height and y >= 0)
					{
						if(grid[y][x] == '#')
							continue;

						if(grid[y][x] == '*')
							++stickers;


						grid[yi][xi] = '+';
						yi = y;
						xi = x;
					}
				break;
			}
		}

		cout << stickers << "\n";
	}

	return 0;
}