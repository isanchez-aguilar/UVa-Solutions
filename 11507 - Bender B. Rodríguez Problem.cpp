/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11507 - Bender B. Rodríguez Problem
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Matrix of instructions' state.
	int instructions[6][6] = 
	{
		{0, 0, 2, 3, 4, 5},
		{0, 1, 3, 2, 5, 4},
		{2, 2, 1, 0, 2, 2},
		{3, 3, 0, 1, 3, 3},
		{4, 4, 4, 4, 1, 0},
		{5, 5, 5, 5, 0, 1}
	};
	int length;
	// Read while the length is nonzero.
	while(cin >> length && length)
	{
		string instruction;
		// Initial direction.
		int direction = 0;
		// Read the (length - 1) instructions.
		while(--length)
		{
			// Read the instruction.
			cin >> instruction;
			int instructionDirection;
			// Get the index of instruction.
			switch(instruction[0])
			{
				case 'N':
					break;
				case '-':
					switch(instruction[1])
					{
						case 'x':
							instructionDirection = 1;
							break;
						case 'y':
							instructionDirection = 3;
							break;
						case 'z':
							instructionDirection = 5;
							break;							
					}
					break;
				default:
					switch(instruction[1])
					{
						case 'x':
							instructionDirection = 0;
							break;
						case 'y':
							instructionDirection = 2;
							break;
						case 'z':
							instructionDirection = 4;
							break;							
					}
			}
			// Change to new direction with the matrix of states.
			if(instruction[0] != 'N')
				direction = instructions[direction][instructionDirection];
		}
		// Get the string of instrcution with the number.
		switch(direction)
		{
			case 0:
				cout << "+x\n";
				break;
			case 1:
				cout << "-x\n";
				break;
			case 2:
				cout << "+y\n";
				break;
			case 3:
				cout << "-y\n";
				break;
			case 4:
				cout << "+z\n";
				break;
			case 5:
				cout << "-z\n";
				break;
		}
	}
	return 0;
}