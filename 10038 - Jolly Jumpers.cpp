/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10038 - Jolly Jumpers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of numbers.
	int numbers;
	// Read while not EOF
	while(cin >> numbers)
	{
		// Array to check the difference;
		vector<bool> differences(numbers - 1); 
		// Variables to make the difference.
		int lastNumber;
		int currentNumber;
		// Read the first number;
		cin >> lastNumber;
		// Read the next numbers to make the difference.
		for(int i = 1; i < numbers; ++i)
		{
			// Read the current number.
			cin >> currentNumber;
			// Get the absolute value of difference between the last and current number.
			int difference = abs(lastNumber - currentNumber);
			// If the difference is on range then save.
			if(difference > 0 && difference < numbers)
				differences[difference - 1] = 1;
			// Update the new current number.
			lastNumber = currentNumber;
		}
		// If all differences between 1 to n - 1 are the is a Jolly
		if(count(differences.begin(), differences.end(), 1) == numbers - 1)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
	return 0;
}