/*
*	User: Isanchez_Aguilar
*	Problem: UVA 340 - Master-Mind Hints
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int length;
	int testCase = 1;
	// Read while the length is not 0.
	while(cin >> length && length)
	{
		vector<int> code(length);
		// Read the code.
		for(int i = 0; i < length; ++i)
			cin >> code[i];
		bool line;
		// print information of game.
		cout << "Game " << testCase++ << ":\n";
	    do
		{
			int number;
			line = 0;
			int strong = 0;
			int normal = 0;
			vector<int> frequence(10, 0);
			vector<int> frequenceCode(10, 0);
			// Read guess code.
			for(int i = 0; i < length; ++i)
			{
				cin >> number;
				// If the current number is equal to code[i] then increase strong matchng. 				
				if(number == code[i])
					++strong;
				// Increase the frequence of current number. 
				else
				{
					++frequenceCode[code[i]];
					++frequence[number];
				}
				// OR to know if it is 0.
				line |= number;
			}
			// If the current line of numbers is not 0.
			if(line)
			{
				// Get the minimum frequence value between the code and guess code.
				for(int i = 0; i < 10; ++i)
					normal += min(frequence[i], frequenceCode[i]);
			
				cout << "    (" << strong << "," << normal << ")\n"; 
			}
		}while(line);
	}
	return 0;
}
