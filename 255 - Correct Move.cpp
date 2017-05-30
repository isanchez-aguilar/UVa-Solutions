/*
*	User: Isanchez_Aguilar
*	Problem: UVA 255 - Correct Move
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int p1;
	int p2;
	int move;
	// Read while not EOF.
	while(cin >> p1 >> p2 >> move)
	{
		// Assume that is possible the firs move.
		bool firstMove = true;
		// If the positions of pieces are same then is a illegal state.
		if(p1 == p2)
		{
			firstMove = false;
			cout << "Illegal state\n";
		}
		else
		{
			// If the current position of piece 2 is equal to the move then is a illegal move.	
			if(p2 == move)
			{
				firstMove = false;
				cout << "Illegal move\n";
			}
			// If the move is possible then check if It is legal.
			if(firstMove && ((p1 - p2) % 8 == 0 && (p2 - move) % 8 == 0) || (p1 / 8 == p2 / 8 && p2 / 8 == move / 8))
			{
				// If the piece 1 is between piece 2 and move then is a illegal move.
				if(p1 <= max(p2, move) && p1 >= min(p2, move))
				{
					firstMove = false;
					cout << "Illegal move\n";
				}
			}
			// If It is a illegal move.
			else if((p2 - move) % 8 && p2 / 8 != move / 8)
			{
				firstMove = false;
				cout << "Illegal move\n";
			}
			// If the first move is possible then check if It is a allowed move.
			if(firstMove)
			{
				//Compute the distance between pice 1 and move.
				int distance = max(p1, move) - min(p1, move);
				// If the distance is 1 and the move and piece 1 are on same horizontal line or the distance is 8.
				if((distance == 1 && p1 / 8 == move / 8) || distance == 8)
				{
					firstMove = false;
					cout << "Move not allowed\n";		
				}
			}
			// If the first move is possible the check if the second is too. 
			if(firstMove)
			{
				// If the piece 1 is on corner and move is too then It is not possible,
				if((!p1 && move == 9) || (p1 == 7 && move == 14) || (p1 == 56 && move == 49) || (p1 == 63 && move == 54))
					cout << "Stop\n";
				else
					cout << "Continue\n";
			}

		}
	}
	return 0;
}