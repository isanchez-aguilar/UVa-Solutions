/*
*	User: Isanchez_Aguilar
*	Problem: UVA 314 - Robot
*/
#include <bits/stdc++.h>

using namespace std;

class Cell
{
public:
	Cell(int _x, int _y, int _direction, int _level):x(_x), y(_y), direction(_direction), level(_level){}
	
	int x;
	int y;
	int level;
	int direction;
};

int r;
int c;
int grid[50][50];

inline bool isValid(int x, int y)
{
	if(x <= 0 or y <= 0 or x >= r or y >= c)
		return false;
	
	if(grid[x - 1][y - 1])
		return false;
	
	if(grid[x - 1][y])
		return false; 
	
	if(grid[x][y-1])
		return false;
	
	if(grid[x][y])
		return false;
	
	return true;
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	while(cin >> r >> c and (r or c))
	{
		
		for(int i = 0; i < r; ++i)
		{
			for(int j = 0; j < c; ++j)
				cin >> grid[i][j];
		}
		
		int sx;
		int sy;
		int tx;
		int ty;
		string s;
		int direction;
		
		cin >> sx >> sy >> tx >> ty >> s;
		
		if(s[0] == 'n')
			direction = 0;
		else if(s[0] == 'e')
			direction = 1;
		else if(s[0] == 's')
			direction = 2;
		else
			direction = 3;

		queue<Cell> node;
		int commands = -1;
		bool visited[r][c][4];

		if(isValid(sx, sy))
		{
			visited[sx][sy][direction] = true;
			node.push(Cell(sx, sy, direction, 0));
			memset(visited, false, sizeof visited);
		}
		
		while(not node.empty())
		{
			Cell u = node.front();
			node.pop();
			
			if(u.x == tx and u.y == ty) 
			{
				commands = u.level;
				break;
			}
			
			if(not visited[u.x][u.y][(u.direction + 1) % 4])
			{
				visited[u.x][u.y][(u.direction + 1) % 4] = true;
				node.push(Cell(u.x, u.y, (u.direction + 1) % 4, u.level + 1));
			}
			
			if(not visited[u.x][u.y][(u.direction + 3) % 4])
			{
				visited[u.x][u.y][(u.direction + 3) % 4] = true;
				node.push(Cell(u.x, u.y, (u.direction + 3) % 4, u.level + 1));
			}
			
			for(int i = 1; i < 4; ++i)
			{
				int x = u.x + moves[u.direction][0] * i;
				int y = u.y + moves[u.direction][1] * i;
			
				if(isValid(x, y))
				{
					if(not visited[x][y][u.direction])
					{	
						visited[x][y][u.direction] = true;
						node.push(Cell(x, y, u.direction, u.level + 1));
					}
				}
				else
					break;
			}
		}

		cout << commands << "\n";
	}
	
	return 0;
}