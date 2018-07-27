/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10267 - Graphical Editor
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

const int adj[4][2] = {
	{-1,  0},
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

char colour;
vvb visited;
vvc currentImage;
char selectedColour;

inline void drawRectangle(int x1, int y1, int x2, int y2, char colour)
{
	for (int i = y1; i <= y2; ++i)
	{
		for (int j = x1; j <= x2; ++j)
			currentImage[i][j] = colour;
	}

	return;
}

inline bool isValid(int x, int y)
{
	return y < currentImage.size() and y > -1 and x < currentImage[y].size() and x > -1;
}

inline void drawRegion(int x, int y)
{
	visited[y][x] = true;
	currentImage[y][x] = colour;

	for (int i = 0; i < 4; ++i)
	{
		int x1 = x + adj[i][0];
		int y1 = y + adj[i][1];

		if (isValid(x1, y1) and not visited[y1][x1] and selectedColour == currentImage[y1][x1])
			drawRegion(x1, y1);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x;
	int y;
	int x1;
	int y1;
	string line;

	while (getline(cin, line) and line != "X")
	{
		istringstream in(line);

		char command;
		in >> command;

		switch (command)
		{
			case 'I':
				int m;
				int n;
				in >> m >> n;
				visited = vvb(n, vb(m, false));
				currentImage = vvc(n, vc(m, 'O'));
			break;
			
			case 'C':
				for (int i = 0; i < currentImage.size(); ++i)
				{
					for (int j = 0; j < currentImage[i].size(); ++j)
						currentImage[i][j] = 'O';
				}
			break;

			case 'L':
				in >> x >> y >> colour;
				currentImage[y - 1][x - 1] = colour;
			break;

			case 'V':
				in >> x >> y >> y1 >> colour;
				
				if (y > y1)
					swap(y, y1);
				
				drawRectangle(x - 1, y - 1, x - 1, y1 - 1, colour);
			break;

			case 'H':
				in >> x >> x1 >> y >> colour;
				
				if (x > x1)
					swap(x, x1);
				
				drawRectangle(x - 1, y - 1, x1 - 1, y - 1, colour);
			break;

			case 'K':
				in >> x >> y >> x1 >> y1 >> colour;

				if (x > x1)
					swap(x, x1);
				
				if (y > y1)
					swap(y, y1);
				
				drawRectangle(x - 1, y - 1, x1 - 1, y1 - 1, colour);
			break;

			case 'F':
				in >> x >> y >> colour;
				selectedColour = currentImage[y - 1][x - 1];

				for (int i = 0; i < visited.size(); ++i)
				{
					for (int j = 0; j < visited[i].size(); ++j)
						visited[i][j] = false;
				}
				
				drawRegion(x - 1, y - 1);
			break;

			case 'S':
				string name;
				in >> name;

				cout << name << "\n";
				for (int y = 0; y < currentImage.size(); ++y)
				{
					for (int x = 0; x < currentImage[y].size(); ++x)
						cout << currentImage[y][x];
					cout << "\n";
				}
			break;
		}
	}

	return 0;
}