/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12187 - Brothers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int width;
	int height;
	int battles;
	int brothers;
	const int moves[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

	while(cin >> brothers >> height >> width >> battles)
	{
		if(!brothers || !height || !width || !battles)
			return 0;

		vector< vector<int> > kingdom(height, vector<int>(width));
		
		vector<int> attack(brothers, 0);
		for(int i = 0; i < brothers - 1; ++i)
			attack[i] = i + 1;	

		for(int i = 0; i < height; ++i)
		{
			for(int j = 0; j < width; ++j)
				cin >> kingdom[i][j];
		}	

		while(battles--)
		{
			vector< vector<int> > temp = kingdom; 
			
			for(int i = 0; i < height; ++i)
			{
				for(int j = 0; j < width; ++j)
				{
					for(int m = 0; m < 4; ++m)
					{
						int y = i + moves[m][0];
						int x = j + moves[m][1];
			
						if(y > -1 && y < height && x > -1 && x < width && attack[kingdom[i][j]] == kingdom[y][x])
							temp[y][x] = kingdom[i][j];	
					}
				}
			}
			
			kingdom = temp;
		}

		for(int i = 0; i < height; ++i)
		{
			for(int j = 0; j < width; ++j)
			{
				cout << kingdom[i][j];
				if(j + 1 < width)
					cout << " ";		
			}
			cout << "\n";
		}
	}
	return 0;
}