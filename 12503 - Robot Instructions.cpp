/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12503 - Robot Instructions
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of test cases.
	int testCases;
	// Read the number of test cases.
	cin >> testCases;
	// Read while there are test cases.
	while(testCases--)
	{
		// Number of instructions.
		int numberInstructions;
		cin >> numberInstructions;
		// Variable to save the current position.
		int position = 0;
		// Values of instructions.
		vector<int> instructions(numberInstructions);
		// Read the instructions.
		for(int i = 0; i < numberInstructions; ++i)
		{
			// Read instruction.
			string instruction;
			cin >> instruction;
			if(instruction == "SAME")
			{
				int j;
				// Read the missing information.
				cin >> instruction >> j;
				// Get the action number j and execute.
				instructions[i] = instructions[--j];
				position += instructions[j];
			}
			// Move to left the robot.
			else if(instruction == "LEFT")
			{
				instructions[i] = -1;
				--position;
			}
			// Move to rigth the robot.
			else
			{
				instructions[i] = 1;
				++position;	
			}
		}
		// Print the las position.
		cout << position << "\n";

	}
	return 0;
}