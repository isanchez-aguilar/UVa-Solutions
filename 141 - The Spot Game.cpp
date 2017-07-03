/*
*	User: Isanchez_Aguilar
*	Problem: UVA 141 - The Spot Game
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

typedef struct pattern
{
	vll rows;
	vll columns;
}Pattern;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int t = 0;
	while(cin >> n && n)
	{
		vll rows(n, 0);
		vll columns(n, 0);
		int winner = -1;
		int winnerMove = -1;
		int numberMoves = n << 1;
		vector<Pattern> moves(0);
		// Read moves.
		for(int i = 0; i < numberMoves; ++i)
		{
			ll x;
			ll y;
			char move;
			cin >> y >> x >> move;
			--y;
			--x;
			if(winner == -1)
			{
				switch(move)
				{
					case '+':
						rows[y] += ((ll)1) << x;
						columns[x] += ((ll)1) << y;
					break;
					default:
						rows[y] -= ((ll)1) << x;
						columns[x] -= ((ll)1) << y;
						
				}
				// Previous patterns.
				for(int j = 0; j < i && winner == -1 && moves.size(); ++j)
				{
					bool isEqual =1;
					// Normal.
					for(int k = 0; k < n; ++k)
					{
						if(rows[k] != moves[j].rows[k])
						{
							isEqual = 0;
							break;
						}
					}
					// Check if the previous pattern is equal than current.
					if(isEqual)
					{
						winnerMove = i + 1;
						winner = (winnerMove & 1) + 1;
					}
					else
					{
						isEqual = 1;
						// 90 deegres.
						for(int k = 0; k < n; ++k)
						{
							if(rows[k] != moves[j].columns[n - k - 1])
							{
								isEqual = 0;
								break;
							}
						}
						if(isEqual)
						{
							winnerMove = i + 1;
							winner = (winnerMove & 1) + 1;
						}
						else
						{
							isEqual = 1;
							// -90 deegres.
							for(int k = 0; k < n; ++k)
							{
								if(columns[k] != moves[j].rows[n - k - 1])
								{
									isEqual = 0;
									break;
								}
							}
							if(isEqual)
							{
								winnerMove = i + 1;
								winner = (winnerMove & 1) + 1;
							}
							else
							{
								isEqual = 1;
								// 180 deegres.
								for(int k = 0; k < n; ++k)
								{
									bitset<50> aux1(rows[k]);
									bitset<50> aux2(moves[j].rows[n - k - 1]);
									int l = 0;
									int m = n - 1;
									while(l < n)
									{
										if(aux1[l++] != aux2[m--])
										{
											isEqual = 0;
											break;
										}
									}
								}
								if(isEqual)
								{
									winnerMove = i + 1;
									winner = (winnerMove & 1) + 1;
								}
							}
						}
					}
				}
				if(winner == -1)
				{
					Pattern aux;
					aux.rows = rows;
					aux.columns = columns;
					moves.push_back(aux);
				}
			}
		}
		if(winner == 1)
			cout << "Player 1 wins on move " << winnerMove << "\n";
		else if(winner == 2)
			cout << "Player 2 wins on move " << winnerMove << "\n";
		else
			cout << "Draw\n";
	}
	return 0;
}