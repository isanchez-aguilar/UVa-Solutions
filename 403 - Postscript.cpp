/*
*	User: Isanchez_Aguilar
*	Problem: UVA 403 - Postscript
*/
#include <bits/stdc++.h>

#define SIZE 60
#define SMALL "C1"

using namespace std;

const char c5[27][31] = {
	{".***.*...*******...**...*"}, // A
	{"****.*...*****.*...*****."}, // B
	{".*****...**....*.....****"}, // C
	{"****.*...**...**...*****."}, // D
	{"******....***..*....*****"}, // E
	{"******....***..*....*...."}, // F
	{".*****....*..***...*.***."}, // G
	{"*...**...*******...**...*"}, // H
	{"*****..*....*....*..*****"}, // I
	{"..***...*....*.*..*..**.."}, // J
	{"*...**..*.***..*..*.*...*"}, // K
	{"*....*....*....*....*****"}, // L
	{"*...***.***.*.**...**...*"}, // M
	{"*...***..**.*.**..***...*"}, // N
	{".***.*...**...**...*.***."}, // O
	{"****.*...*****.*....*...."}, // P
	{".***.*...**...**..**.****"}, // Q
	{"****.*...*****.*..*.*...*"}, // R
	{".*****.....***.....*****."}, // S
	{"******.*.*..*....*...***."}, // T
	{"*...**...**...**...*.***."}, // U
	{"*...**...*.*.*..*.*...*.."}, // V
	{"*...**...**.*.***.***...*"}, // W
	{"*...*.*.*...*...*.*.*...*"}, // X
	{"*...*.*.*...*....*....*.."}, // Y
	{"*****...*...*...*...*****"} // Z
};

char page[SIZE][SIZE];

inline string getString(string s)
{
	return s.substr(s.find_first_of('|') + 1, s.find_last_of('|') - 2);
}

inline void print(const string s, const string font, int x, int y)
{
	if (font == SMALL)
	{
		for (int i = x, j = 0; j < s.length() and i < SIZE; ++i, ++j)
		{
			if (s[j] != ' ')
				page[y][i] = s[j];
		}
	}
	else
	{
		for (int j = 0, currentY = y; j < 5 and currentY < SIZE; ++j, ++currentY)
		{
			for (int i = 0, currentX = x; i < s.length() and currentX < SIZE; ++i)
			{
				for (int k = 0; k < 5 and currentX < SIZE; ++k, ++currentX)
				{
					if (not isalpha(s[i]))
						continue;

					char c = c5[s[i] - 'A'][j * 5 + k];

					if (c == '*' and currentX >= 0)
					{
						page[currentY][currentX] = c;
					}
				}
				// Space after every single letter.
				++currentX;
			}
		}
	}

	return;
}

inline void printPage()
{
	// Print page.
	for (int i = 0; i < 60; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			cout << page[i][j];
			page[i][j] = '.';
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < 60; ++i)
		cout << "-";

	cout << "\n\n";
	
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string command;
	cin >> command;
	
	memset(page, '.', sizeof page);
	
	do
	{
		if (command == ".EOP")
		{
			printPage();
			continue;
		}
		
		int row;
		string font;
		cin >> font >> row;
		
		if (command == ".P")
		{
			string s;
			int column;

			cin >> column;
			getline(cin, s);

			print(getString(s), font, column - 1, row - 1);
		}
		else
		{
			string s;
			getline(cin, s);
			s = getString(s);
			
			if (command == ".L")
				print(s, font, 0, row - 1);
				
			else if (command == ".R")
			{
				int column = 60;
				int length = s.length();

				if (font != SMALL)
					length *= 6;

				column -= length;

				print(s, font, column, row - 1);
			}
			else
			{
				int column = 0;
				int length = s.length();
				
				if (font != SMALL)
					length *= 6;

				int start = 0;
				column = 30 - (length >> 1);

				print(s, font, column, row - 1);
			}
		}
	} while(cin >> command);


	return 0;
}