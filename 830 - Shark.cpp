/*
*	User: Isanchez_Aguilar
*	Problem: UVA 830 - Shark
*/
#include <bits/stdc++.h>

#define MAX 128

using namespace std;

const int adj[4][2] = {
	{-1,  0},
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

char c;
int width;
int height;
int lowestX;
int lowestY;
int biggestX;
int biggestY;
char sea[MAX][MAX];
bool visited[MAX][MAX];

inline bool isValid(int x, int y)
{
	return x > -1 and x < width and y > -1 and y < height;
}

inline void searchNeighbors(int y, int x)
{
	visited[y][x] = true;
	
	for (int v = 0; v < 4; ++v)
	{
		int i = y + adj[v][0];
		int j = x + adj[v][1];
		
		if (isValid(j, i) and sea[i][j] == c and not visited[i][j])
		{
			lowestX = min(lowestX, j);
			lowestY = min(lowestY, i);

			biggestX = max(biggestX, j);
			biggestY = max(biggestY, i);

			searchNeighbors(i, j);
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	int frequencies[8];
	
	cin >> testCases;

	while (testCases--)
	{
		cin >> height >> width;
		memset(visited, false, sizeof visited);

		for (int i = 0; i < height; ++i)
			cin >> sea[i];

		memset(frequencies, 0, sizeof frequencies);

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (sea[i][j] >= 'a' and sea[i][j] <= 'z' and not visited[i][j])
				{
					lowestX = j;
					lowestY = i;
					biggestX = j;
					biggestY = i;

					c = sea[i][j];
					searchNeighbors(i, j);

					bool isShark = false;
					for (int y = lowestY; y <= biggestY; ++y)
					{	
						for (int x = lowestX; x <= biggestX; ++x)
						{
								if (sea[y][x] != c or sea[y][x] != c)
								{
									isShark = true;
									break;
								}
						}
					}

					if (isShark)
						++frequencies[7];
					else
					{
						int w = biggestX - lowestX + 1;
						int h = biggestY - lowestY + 1;

						if (h < w)
							swap(w, h);

						if (w == 1 and h == 1)
						{

							++frequencies[0];
						}
						else if (w == 1 and h == 2)
							++frequencies[1];
						else if (w == 1 and h > 2)
							++frequencies[2];
						else if (w == 2 and h > 2)
							++frequencies[3];
						else if (w == h)
							++frequencies[4];
						else if (w == 3 and h > 3)
							++frequencies[5];
						else
							++frequencies[6];
					}
				}
			}
		}


		for (int i = 0; i < 8; ++i)
		{
			if (i)
				cout << " ";
			
			cout << frequencies[i];
		}
		
		cout << "\n";

		if (testCases)
			cout << "\n";
	}

	return 0;
}