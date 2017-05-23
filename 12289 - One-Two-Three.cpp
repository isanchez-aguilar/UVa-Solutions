/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12289 - One-Two-Three
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
	// While there are test cases.
	while(testCases--)
	{
		// Variable to save the written number.
		string number;
		// Read the written number.
		cin >> number;
		// If the length of the number written is 5 then it is the number 3.
		if(number.length() == 5)
			cout << 3 << "\n";
		// If the length of the number written is not 5 then it is the number 1 or 2.
		else
		{
			// Variables to know the same letters of 1 or 2.
			int charactersEqualOne = 0;
			int charactersEqualTwo = 0;
			// Array of number names
			const string one_two[] = {"one", "two"};
			// Compare the letters of names.
			for(int i = 0; i < 3; ++i)
			{
				// If is the same letter as the. 
				if(one_two[0][i] == number[i])
					++charactersEqualOne;
				// If is the same letter as the 2.
				else if(one_two[1][i] == number[i])
					++charactersEqualTwo;
			}
			// If the matches with 1 are greater than 2.
			if(charactersEqualOne > charactersEqualTwo)
				cout << 1 << "\n";
			// If the matches with 2 are greater than 1.
			else
				cout << 2 << "\n";
		}	
	}
	return 0;
}