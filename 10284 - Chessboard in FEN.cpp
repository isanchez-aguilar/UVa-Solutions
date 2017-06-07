/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10284 - Chessboard in FEN
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vpi;
vector<vpi> chessboard(8, vpi(8));

inline void rookAttack(int y, int x)
{
	for(int i = y + 1; i < 8; ++i)
	{
		if(chessboard[i][x].second != -1 && chessboard[i][x].second != 2)
			break;
		chessboard[i][x].second = -1;
	}
	for(int i = y - 1; i > -1; --i)
	{
		if(chessboard[i][x].second != -1 && chessboard[i][x].second != 2)
			break;
		chessboard[i][x].second = -1;
	}
	for(int j = x + 1; j < 8; ++j)
	{
		if(chessboard[y][j].second != -1 && chessboard[y][j].second != 2)
			break;
		chessboard[y][j].second = -1;
	}
	for(int j = x - 1; j > -1; --j)
	{
		if(chessboard[y][j].second != -1 && chessboard[y][j].second != 2)
			break;
		chessboard[y][j].second = -1;	
	}
	return;
}


inline void bishopAttack(int y, int x)
{
	for(int i = y + 1, j = x + 1; i < 8 && j < 8; ++i, ++j)
	{
		if(chessboard[i][j].second != -1 && chessboard[i][j].second != 2)
			break;
		chessboard[i][j].second = -1;
	}
	for(int i = y + 1, j = x - 1; i < 8 && j > -1; ++i, --j)
	{
		if(chessboard[i][j].second != -1 && chessboard[i][j].second != 2)
			break;
		chessboard[i][j].second = -1;
	}
	for(int i = y - 1, j = x + 1; i > -1 && j < 8; --i, ++j)
	{
		if(chessboard[i][j].second != -1 && chessboard[i][j].second != 2)
			break;
		chessboard[i][j].second = -1;
	}
	for(int i = y - 1, j = x - 1; i > -1 && j > -1; --i, --j)
	{
		if(chessboard[i][j].second != -1 && chessboard[i][j].second != 2)
			break;
		chessboard[i][j].second = -1;
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	string notation;
	// Read the notation.
	while(cin >> notation)
	{
		int x = 0;
		int y = 0;
		// Convert the notation to chessboard.
		for(int i = 0; i < notation.length(); ++i)
		{
			char current = notation[i];
			if(isdigit(current))
			{
				int limit = current - '0';
				for(int j = x; j < x + limit; ++j)
				{
					chessboard[y][j].first = 0;
					chessboard[y][j].second = 2;
				}
				x += limit;
			}
			else
			{
				bool isWhite = 1;
				if(islower(current))
				{
					isWhite = 0;
					current = toupper(current);
				}
				switch(current)
				{
					case 'P':
						chessboard[y][x++].first = 1; 
					break;
					case 'N':
						chessboard[y][x++].first = 2; 
					break;
					case 'B':
						chessboard[y][x++].first = 3; 
					break;
					case 'R':
						chessboard[y][x++].first = 4; 
					break;
					case 'Q':
						chessboard[y][x++].first = 5; 
					break;
					case 'K':
						chessboard[y][x++].first = 6;
					break;
					default:
						++y;
						x = 0;
				}
				if(current != '/')
				{
					if(isWhite)
						chessboard[y][x - 1].second = 0;
					else
					 	chessboard[y][x - 1].second = 1;
				}
			}
		}
		// Fill the remaining rows.
		for(y += 1; y < 8; ++y)
		{
			for(int j = 0; j < 8; ++j)
			{
					chessboard[y][j].first = 0;
					chessboard[y][j].second = 2;
			}
		}
		// Initialize the unoccupied places.
		int unoccupied = 64;
		// Check the attack of pieces.
		for(int i = 0; i < 8; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{
				switch(chessboard[i][j].first)
				{
					case 1:
						if(chessboard[i][j].second)
						{
							if(i < 7)
							{
								if(j < 7)
								{
									if(chessboard[i + 1][j + 1].second == 2)
										chessboard[i + 1][j + 1].second = -1;
								}
								if(j > 0)
								{
									if(chessboard[i + 1][j - 1].second == 2)
										chessboard[i + 1][j - 1].second = -1;
								}

							}
						}
						else
						{
							if(i > 0)
							{
								if(j < 7)
								{
									if(chessboard[i - 1][j + 1].second == 2)
										chessboard[i - 1][j + 1].second = -1;
								}
								if(j > 0)
								{
									if(chessboard[i - 1][j - 1].second == 2)
										chessboard[i - 1][j - 1].second = -1;
								}
							}
						}
					break;
					case 2:
						if(i < 7)
						{
							if(i < 6)
							{
								if(j < 7)
								{
									if(chessboard[i + 2][j + 1].second == 2)
										chessboard[i + 2][j + 1].second = -1;
								}	
								if(j > 0)
								{
									if(chessboard[i + 2][j - 1].second == 2)
										chessboard[i + 2][j - 1].second = -1; 
								}				
							}
							if(j < 6)
							{
								if(chessboard[i + 1][j + 2].second == 2)
									chessboard[i + 1][j + 2].second = -1;
							}
							if(j > 1)
							{
								if(chessboard[i + 1][j - 2].second == 2)
									chessboard[i + 1][j - 2].second = -1;
							}
						}
						if(i > 0)
						{
							if(i > 1)
							{
								if(j < 7)
								{
									if(chessboard[i - 2][j + 1].second == 2)
										chessboard[i - 2][j + 1].second = -1;
								}	
								if(j > 0)
								{
									if(chessboard[i - 2][j - 1].second == 2)
										chessboard[i - 2][j - 1].second = -1; 
								}	
							}
							if(j < 6)
							{
								if(chessboard[i - 1][j + 2].second == 2)
									chessboard[i - 1][j + 2].second = -1;
							}
							if(j > 1)
							{
								if(chessboard[i - 1][j - 2].second == 2)
									chessboard[i - 1][j - 2].second = -1;								
							}
						}
					break;
					case 3:
						bishopAttack(i, j);
					break;
					case 4:
						rookAttack(i, j);
					break;
					case 5:
						bishopAttack(i, j);
						rookAttack(i, j);
					break;
					case 6:
						for(int y = i - 1; y < i + 2; ++y)
						{
							for(int x = j - 1; x < j + 2; ++x)
							{
								if(y > -1 && y < 8 && x > -1 && x < 8 && (y != i || x != j))
								{
									if(chessboard[y][x].second == 2)
										chessboard[y][x].second = -1;
								}
							}
						}
					break;	
				}
			}
		}
		// Count the unoccupied pieces.
		for(int i = 0; i < 8; ++i)
		{
			for(int j = 0; j < 8; ++j)
				if(chessboard[i][j].second != 2)
					--unoccupied;
		}
		// print the unoccupied pieces.
		cout << unoccupied << '\n';
	}
	return 0;
}
