/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10196 - Check The Check
*/
#include <bits/stdc++.h>

using namespace std;

bool isEmpty;
bool checkBlack;
bool checkWhite;
vector<string> chessBoard(8);

inline void bishopMoves(int y, int x, char colour)
{
	for(int i = y + 1, j = x + 1; i < 8 && j < 8; ++i, ++j)
	{
		if(colour == '1')
		{
			if(chessBoard[i][j] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[i][j] == '2')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '1')
				chessBoard[i][j] = '1';
			else if(chessBoard[i][j] != '3')
				break;

		}
		else
		{
			if(chessBoard[i][j] == 'K')
			{
				checkWhite = 1;
				break;
			}
			else if(chessBoard[i][j] == '1')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '2')
				chessBoard[i][j] = '2';
			else if(chessBoard[i][j] != '3')
				break;		
		}
	}
	for(int i = y + 1, j = x - 1; i < 8 && j > -1; ++i, --j)
	{
		if(colour == '1')
		{
			if(chessBoard[i][j] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[i][j] == '2')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '1')
				chessBoard[i][j] = '1';
			else if(chessBoard[i][j] != '3')
				break;

		}
		else
		{
			if(chessBoard[i][j] == 'K')
			{
				checkWhite = 1;
				break;
			}
			else if(chessBoard[i][j] == '1')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '2')
				chessBoard[i][j] = '2';
			else if(chessBoard[i][j] != '3')
				break;		
		}
	}

	for(int i = y - 1, j = x + 1; i > -1 && j < 8; --i, ++j)
	{
		if(colour == '1')
		{
			if(chessBoard[i][j] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[i][j] == '2')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '1')
				chessBoard[i][j] = '1';
			else if(chessBoard[i][j] != '3')
				break;
		}
		else
		{
			if(chessBoard[i][j] == 'K')
			{ 
				checkWhite = 1;
				break;
			}
			else if(chessBoard[i][j] == '1')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '2')
				chessBoard[i][j] = '2';
			else if(chessBoard[i][j] != '3')
				break;		
		}
	}
	for(int i = y - 1, j = x - 1; i > -1 && j > -1; --i, --j)
	{
		if(colour == '1')
		{
			if(chessBoard[i][j] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[i][j] == '2')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '1')
				chessBoard[i][j] = '1';
			else if(chessBoard[i][j] != '3')
				break;

		}
		else
		{
			if(chessBoard[i][j] == 'K')
			{
				checkWhite = 1;
				break;
			}
			else if(chessBoard[i][j] == '1')
				chessBoard[i][j] = '3';
			else if(chessBoard[i][j] == '.' || chessBoard[i][j] == '2')
				chessBoard[i][j] = '2';
			else if(chessBoard[i][j] != '3')
				break;		
		}
	}
	return;
}

inline void rookMoves(int y, int x, char colour)
{
	for(int i = y + 1; i < 8; ++i)
	{
		if(colour == '1')
		{
			if(chessBoard[i][x] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[i][x] == '2')
				chessBoard[i][x] = '3';
			else if(chessBoard[i][x] == '.' || chessBoard[i][x] == '1')
				chessBoard[i][x] = '1';
			else if(chessBoard[i][x] != '3')
				break;

		}
		else
		{
			if(chessBoard[i][x] == 'K')
			{
				checkWhite = 1;
				break;
			}
			else if(chessBoard[i][x] == '1')
				chessBoard[i][x] = '3';
			else if(chessBoard[i][x] == '.' || chessBoard[i][x] == '2')
				chessBoard[i][x] = '2';
			else if(chessBoard[i][x] != '3')
				break;		
		}
	}
	for(int i = y - 1; i > -1; --i)
	{
		if(colour == '1')
		{
			if(chessBoard[i][x] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[i][x] == '2')
				chessBoard[i][x] = '3';
			else if(chessBoard[i][x] == '.' || chessBoard[i][x] == '1')
				chessBoard[i][x] = '1';
			else if(chessBoard[i][x] != '3')
				break;

		}
		else
		{
			if(chessBoard[i][x] == 'K')
			{
				checkWhite = 1;
				break;
			}
			else if(chessBoard[i][x] == '1')
				chessBoard[i][x] = '3';
			else if(chessBoard[i][x] == '.' || chessBoard[i][x] == '2')
				chessBoard[i][x] = '2';
			else if(chessBoard[i][x] != '3')
				break;		
		}
	}

	for(int j = x + 1; j < 8; ++j)
	{
		if(colour == '1')
		{
			if(chessBoard[y][j] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[y][j] == '2')
				chessBoard[y][j] = '3';
			else if(chessBoard[y][j] == '.' || chessBoard[y][j] == '1')
				chessBoard[y][j] = '1';
			else if(chessBoard[y][j] != '3')
				break;

		}
		else
		{
			if(chessBoard[y][j] == 'K')
			{
				checkWhite = 1;
				break;
			}
			else if(chessBoard[y][j] == '1')
				chessBoard[y][j] = '3';
			else if(chessBoard[y][j] == '.' || chessBoard[y][j] == '2')
				chessBoard[y][j] = '2';
			else if(chessBoard[y][j] != '3')
				break;		
		}
	}
	for(int j = x - 1; j > -1; --j)
	{
		if(colour == '1')
		{
			if(chessBoard[y][j] == 'k')
			{
				checkBlack = 1;
				break;
			}
			else if(chessBoard[y][j] == '2')
				chessBoard[y][j] = '3';
			else if(chessBoard[y][j] == '.' || chessBoard[y][j] == '1')
				chessBoard[y][j] = '1';
			else if(chessBoard[y][j] != '3')
				break;

		}
		else
		{
			if(chessBoard[y][j] == 'K')
			{
				checkWhite = 1;
				break;
			}
			else if(chessBoard[y][j] == '1')
				chessBoard[y][j] = '3';
			else if(chessBoard[y][j] == '.' || chessBoard[y][j] == '2')
				chessBoard[y][j] = '2';
			else if(chessBoard[y][j] != '3')
				break;		
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCase = 0;
	// While there is a chessboard.
	while(cin >> chessBoard[0])
	{
		// Assume the chessboard is empty and the colours is not in check.
		isEmpty = 1;
		checkBlack = 0;
		checkWhite = 0;
		// Read the chessboard.
		for(int i = 1; i < 8; ++i)
			cin >> chessBoard[i];
		// Check the pieces while there is not check.
		for(int i = 0; i < 8 && !checkWhite && !checkBlack; ++i)
		{
			for(int j = 0; j < 8 && !checkWhite && !checkBlack; ++j)
			{
				// If the current caracter is different of dot, one, two and three.
				if(chessBoard[i][j] != '.' && chessBoard[i][j] != '1' && chessBoard[i][j] != '2' && chessBoard[i][j] != '3')
				{
					// If there is a piece then the chessboard is not empty.
					isEmpty = 0;
					// Check the rules of each piece.
					if(islower(chessBoard[i][j]))
					{
						switch(chessBoard[i][j])
						{
							case 'p':
								if(i < 7)
								{
									if(j < 7)
									{	
										if(chessBoard[i + 1][j + 1] == 'K')
											checkWhite = 1; 
										else if(chessBoard[i + 1][j + 1] == '.')
											chessBoard[i + 1][j + 1] = '2';
										else if(chessBoard[i + 1][j + 1] == '1')
											chessBoard[i + 1][j + 1] = '3';
									}
									if(j > 0)
									{
										if(chessBoard[i + 1][j - 1] == 'K')
											checkWhite = 1;	
										else if(chessBoard[i + 1][j - 1] == '.')
											chessBoard[i + 1][j - 1] = '2';
										else if(chessBoard[i + 1][j - 1] == '1')
											chessBoard[i + 1][j - 1] = '3';
									}
								}
							break;
							case 'r':
								rookMoves(i, j, '2');							
							break;
							case 'b':
								bishopMoves(i, j, '2');
							break;
							case 'n':
								if(i < 6)
								{
									if(j < 7)
									{
										if(chessBoard[i + 2][j + 1] == 'K')
											checkWhite = 1;
										else if(chessBoard[i + 2][j + 1] == '.')
											chessBoard[i + 2][j + 1] = '2';
										else if(chessBoard[i + 2][j + 1] == '1')
											chessBoard[i + 2][j + 1] = '3';
									}
									if(j > 0)
									{
										if(chessBoard[i + 2][j - 1] == 'K')
											checkWhite = 1;	
										else if(chessBoard[i + 2][j - 1] == '.')
											chessBoard[i + 2][j - 1] = '2';
										else if(chessBoard[i + 2][j - 1] == '1')
											chessBoard[i + 2][j - 1] = '3';
									}
								}
								if(i > 1)
								{
									if(j < 7)
									{
										if(chessBoard[i - 2][j + 1] == 'K')
											checkWhite = 1;
										else if(chessBoard[i - 2][j + 1] == '.')
											chessBoard[i - 2][j + 1] = '2';
										else if(chessBoard[i - 2][j + 1] == '1')
											chessBoard[i - 2][j + 1] = '3';
									}
									if(j > 0)
									{
										if(chessBoard[i - 2][j - 1] == 'K')
											checkWhite = 1;	
										else if(chessBoard[i - 2][j - 1] == '.')
											chessBoard[i - 2][j - 1] = '2';
										else if(chessBoard[i - 2][j - 1] == '1')
											chessBoard[i - 2][j - 1] = '3';
									}
								}
								if(i < 7)
								{
									if(j < 6)
									{
										if(chessBoard[i + 1][j + 2] == 'K')
											checkWhite = 1;
										else if(chessBoard[i + 1][j + 2] == '.')
											chessBoard[i + 1][j + 2] = '2';
										else if(chessBoard[i + 1][j + 2] == '1')
											chessBoard[i + 1][j + 2] = '3';
									}
									if(j > 1)
									{
										if(chessBoard[i + 1][j - 2] == 'K')
											checkWhite = 1;	
										else if(chessBoard[i + 1][j - 2] == '.')
											chessBoard[i + 1][j - 2] = '2';
										else if(chessBoard[i + 1][j - 2] == '1')
											chessBoard[i + 1][j - 2] = '3';
									}
								}
								if(i > 0)
								{
									if(j < 6)
									{
										if(chessBoard[i - 1][j + 2] == 'K')
											checkWhite = 1;
										else if(chessBoard[i - 1][j + 2] == '.')
											chessBoard[i - 1][j + 2] = '2';
										else if(chessBoard[i - 1][j + 2] == '1')
											chessBoard[i - 1][j + 2] = '3';
									}
									if(j > 1)
									{
										if(chessBoard[i - 1][j - 2] == 'K')
											checkWhite = 1;	
										else if(chessBoard[i - 1][j - 2] == '.')
											chessBoard[i - 1][j - 2] = '2';
										else if(chessBoard[i - 1][j - 2] == '1')
											chessBoard[i - 1][j - 2] = '3';
									}
								}
							break;
							case 'q':
								rookMoves(i, j, '2');
								bishopMoves(i, j, '2');
							break;
							case 'k':
								if(chessBoard[i][j] == '1' || chessBoard[i][j] == '3')
									checkBlack = 1;
							break;
						}
					}
					else
					{
						switch(chessBoard[i][j])
						{
							case 'P':
								if(i > 1)
								{
									if(j < 7)
									{
										if(chessBoard[i - 1][j + 1] == 'k')
											checkBlack = 1;
										else if(chessBoard[i - 1][j + 1] == '.')
											chessBoard[i - 1][j + 1] = '1';
										else if(chessBoard[i - 1][j + 1] == '2')
											chessBoard[i - 1][j + 1] = '3';
									}
									if(j > 0)
									{
										if(chessBoard[i - 1][j - 1] == 'k')
											checkBlack = 1;	
										else if(chessBoard[i - 1][j - 1] == '.')
											chessBoard[i - 1][j - 1] = '1';
										else if(chessBoard[i - 1][j - 1] == '2')
											chessBoard[i - 1][j - 1] = '3';
									}
								}
							break;
							case 'R':
								rookMoves(i, j, '1');							
							break;
							case 'B':
								bishopMoves(i, j, '1');
							break;
							case 'N':
								if(i < 6)
								{
									if(j < 7)
									{
										if(chessBoard[i + 2][j + 1] == 'k')
											checkBlack = 1;
										else if(chessBoard[i + 2][j + 1] == '.')
											chessBoard[i + 2][j + 1] = '1';
										else if(chessBoard[i + 2][j + 1] == '2')
											chessBoard[i + 2][j + 1] = '3';
									}
									if(j > 0)
									{
										if(chessBoard[i + 2][j - 1] == 'k')
											checkBlack = 1;	
										else if(chessBoard[i + 2][j - 1] == '.')
											chessBoard[i + 2][j - 1] = '1';
										else if(chessBoard[i + 2][j - 1] == '2')
											chessBoard[i + 2][j - 1] = '3';
									}
								}
								if(i > 1)
								{
									if(j < 7)
									{
										if(chessBoard[i - 2][j + 1] == 'k')
											checkBlack = 1;
										else if(chessBoard[i - 2][j + 1] == '.')
											chessBoard[i - 2][j + 1] = '1';
										else if(chessBoard[i - 2][j + 1] == '2')
											chessBoard[i - 2][j + 1] = '3';
									}
									if(j > 0)
									{
										if(chessBoard[i - 2][j - 1] == 'k')
											checkBlack = 1;	
										else if(chessBoard[i - 2][j - 1] == '.')
											chessBoard[i - 2][j - 1] = '1';
										else if(chessBoard[i - 2][j - 1] == '2')
											chessBoard[i - 2][j - 1] = '3';
									}
								}
								if(i < 7)
								{
									if(j < 6)
									{
										if(chessBoard[i + 1][j + 2] == 'k')
											checkBlack = 1;
										else if(chessBoard[i + 1][j + 2] == '.')
											chessBoard[i + 1][j + 2] = '1';
										else if(chessBoard[i + 1][j + 2] == '2')
											chessBoard[i + 1][j + 2] = '3';
									}
									if(j > 1)
									{
										if(chessBoard[i + 1][j - 2] == 'k')
											checkBlack = 1;	
										else if(chessBoard[i + 1][j - 2] == '.')
											chessBoard[i + 1][j - 2] = '1';
										else if(chessBoard[i + 1][j - 2] == '2')
											chessBoard[i + 1][j - 2] = '3';
									}
								}
								if(i > 0)
								{
									if(j < 6)
									{
										if(chessBoard[i - 1][j + 2] == 'k')
											checkBlack = 1;
										else if(chessBoard[i - 1][j + 2] == '.')
											chessBoard[i - 1][j + 2] = '1';
										else if(chessBoard[i - 1][j + 2] == '2')
											chessBoard[i - 1][j + 2] = '3';
									}
									if(j > 1)
									{
										if(chessBoard[i - 1][j - 2] == 'k')
											checkBlack = 1;	
										else if(chessBoard[i - 1][j - 2] == '.')
											chessBoard[i - 1][j - 2] = '1';
										else if(chessBoard[i - 1][j - 2] == '2')
											chessBoard[i - 1][j - 2] = '3';
									}
								}
							break;
							case 'Q':
								rookMoves(i, j, '1');
								bishopMoves(i, j, '1');
							break;
							case 'K':
								if(chessBoard[i][j] == '2' || chessBoard[i][j] == '3')
									checkWhite = 1;
							break;
						}
					}
				}
			}
		}
		// If the chessboard is empty then finish the execution.	
		if(isEmpty)
			return 0;
		// Print the informamtion.
		cout << "Game #" << ++testCase << ": ";
		if(checkBlack)
			cout << "black king is in check.\n";
		else if(checkWhite)
			cout << "white king is in check.\n";
		else
			cout << "no king is in check.\n";
	}
	return 0;
}