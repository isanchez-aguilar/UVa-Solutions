/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11094 - Continents
*/
#include <bits/stdc++.h>

using namespace std;

int r;
int c;
char land;
string grid[20];
bool visited[20][20];

inline int dfs(int x, int y)
{
	if(y == c)
		y = 0;
	else if(y == -1)
		y= c - 1;
	
	if(x < 0 or x >= r or y < 0 or y >= c)
		return 0;
	
	if(visited[x][y])
		return 0;
	
	if(grid[x][y] != land)
		return 0;

	visited[x][y]= true;

	int cc = 1;
	cc += dfs(x, y - 1);
	cc += dfs(x, y + 1);
	cc += dfs(x + 1, y);
	cc += dfs(x - 1, y);

	return cc;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> r >> c)
	{
		cin.ignore();
		for(int i = 0; i < r; ++i)
			getline(cin, grid[i]);


		int x;
		int y;
		cin >> x >> y;
		
		land = grid[x][y];
		memset(visited, false, sizeof(visited));

		dfs(x, y);
		int biggest = 0;

		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < c; ++j)
			{
				if(grid[i][j] == land)
					biggest = max(biggest, dfs(i, j));
			}
		}

		cout << biggest << "\n";
	}

	return 0;
}