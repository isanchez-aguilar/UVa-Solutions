/*
*	User: Isanchez_Aguilar
*	Problem: UVA 220 - Othello
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<ii> sii;

const int moves[][2] = {
	{1, 1},
	{-1, -1},
	{1, -1},
	{-1, 1},
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1}
};
int numberWhite;
int numberBlack;
char board[8][8];
const char turns[2] = {'W', 'B'};

inline bool isInside(int x, int y)
{
	return x > -1 and x < 8 and y > -1 and y < 8;
}

inline sii getLegalMoves(sii &pieces, int colour)
{
	sii legalMoves;

	for (sii::iterator i = pieces.begin(); i != pieces.end(); ++i)
	{
		int x = i->first;
		int y = i->second;
		for (int j = 0; j < 8; ++j)
		{
			int x1 = x + moves[j][0];
			int y1 = y + moves[j][1];
			bool previousEnemyPiece = false;
		
			while (isInside(x1, y1))
			{
				if (board[x1][y1] == turns[colour])
					break;
				if (board[x1][y1] == '-')
				{
					if (previousEnemyPiece)
						legalMoves.insert(ii(x1 + 1, y1 + 1));
			
					break;
				}
				else if (board[x1][y1] == turns[(colour + 1) & 1])
					previousEnemyPiece = true;

				x1 += moves[j][0];
				y1 += moves[j][1];
			}
		}
	}

	return legalMoves;
}

inline void makeMove(int x, int y, int colour, int &frequencyCurrent, int &frequencyEnemy, sii &current, sii &enemy)
{
	++frequencyCurrent;
	current.insert(ii(x, y));
	board[x][y] = turns[colour];


	for (int j = 0; j < 8; ++j)
	{
		int x1 = x + moves[j][0];
		int y1 = y + moves[j][1];
		bool previousEnemyPiece = false;
	
		while (isInside(x1, y1))
		{
			if (board[x1][y1] == turns[colour])
			{
				if (previousEnemyPiece)
				{
					while (x1 != x or y1 != y)
					{
						x1 -= moves[j][0];
						y1 -= moves[j][1];

						board[x1][y1] = turns[colour];
						current.insert(ii(x1, y1));
						sii::iterator piece = enemy.find(ii(x1, y1));
						if (piece != enemy.end())
						{
							--frequencyEnemy;
							++frequencyCurrent;
							enemy.erase(piece);
						}
					}
				}
				break;
			}
			if (board[x1][y1] == '-')
				break;
			else if (board[x1][y1] == turns[(colour + 1) & 1])
				previousEnemyPiece = true;

			x1 += moves[j][0];
			y1 += moves[j][1];
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		sii black;
		sii white;
		numberBlack = 0;
		numberWhite = 0;

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				cin >> board[i][j];

				if (board[i][j] == 'W')
				{
					++numberWhite;
					white.insert(ii(i, j));
				}
				else if (board[i][j] == 'B')
				{
					++numberBlack;
					black.insert(ii(i, j));
				}
			}
		}

		char c;
		cin >> c;

		int turn = (c == 'W'?0:1);
		while (cin >> c and c != 'Q')
		{
			if (c == 'L')
			{
				sii legalMoves = getLegalMoves((turn?black:white), turn);
				
				if (legalMoves.size())
				{	
					for (sii::iterator i = legalMoves.begin(); i != legalMoves.end(); ++i)
						cout << "(" << i->first << "," << i->second << ")" << (i == --legalMoves.end()?"\n":" ");
				}
				else
				{
					cout << "No legal move.\n";
					turn = (turn + 1) & 1;	
				}
			}
			else
			{
				int x;
				int y;
				cin >> x;

				y = x % 10;
				x /= 10;

				makeMove(x - 1, y - 1, turn, (turn?numberBlack:numberWhite), (turn?numberWhite:numberBlack), (turn?black:white), (turn?white:black));
				
				turn = (turn + 1) & 1;
				cout << "Black - " << setw(2) << numberBlack << " " << "White - " << setw(2) << numberWhite << "\n"; 
			}

		}

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
				cout << board[i][j];
			cout << "\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}