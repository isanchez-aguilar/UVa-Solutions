/*
*	User: Isanchez_Aguilar
*	Problem: UVA 337 - Interpreting Control Sequences
*/
#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;

ii cursor;
bool insertMode;
char terminal[10][10];

inline void writeOnTerminal(char c)
{
	if (insertMode)
	{
		for (int i = 9; i > cursor.x; --i)
			terminal[cursor.y][i] = terminal[cursor.y][i - 1];
	}
	
	terminal[cursor.y][cursor.x] = c;

	if (cursor.x < 9)
		++cursor.x;

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;
	insertMode = false;

	while (cin >> n and n)
	{
		cursor = make_pair(0, 0);
		memset(terminal, ' ', sizeof terminal);

		string line;
		getline(cin, line);

		for (int i = 0; i < n; ++i)
		{
			getline(cin, line);

			for (int j = 0; j < line.length(); ++j)
			{
				if (line[j] == '^')
				{
					switch (line[++j])
					{
						case 'b':
							cursor.x = 0;
						break;
						case 'c':
							memset(terminal, ' ', sizeof terminal);
						break;
						case 'd':
							if (cursor.y < 9)
								++cursor.y;
						break;
						case 'e':
							fill(terminal[cursor.y] + cursor.x, terminal[cursor.y] + 10, ' ');
						break;
						case 'h':
							cursor.x = 0;
							cursor.y = 0;
						break;
						case 'i':
							insertMode = true;
						break;
						case 'l':
							if (cursor.x > 0)
								--cursor.x;		
						break;
						case 'o':
							insertMode = false;
						break;
						case 'r':
							if (cursor.x < 9)
								++cursor.x;
						break;
						case 'u':
							if (cursor.y > 0)
								--cursor.y;
						break;
						case '^':
							writeOnTerminal('^');
						break;
						default:
							cursor.y = line[j] - '0';
							cursor.x = line[++j] - '0';
						break;	
					}
				}
				else
					writeOnTerminal(line[j]);
			}
		}

		cout << "Case " << ++t << "\n";

		cout << "+----------+\n";
		for (int i = 0; i <= 9; ++i)
		{
			cout << "|";

			for (int j = 0; j <= 9; ++j)
				cout << terminal[i][j];

			cout << "|\n";
		}
		cout << "+----------+\n";
	}

	return 0;
}