/*
*	User: Isanchez_Aguilar
*	Problem: UVA 621 - Secret Research
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
		// Variable to save the sequence of digits.
		string sequence;
		// Read the sequence of digits.
		cin >> sequence;
		// Variable to save the length of sequence.
		int length = sequence.length();
		// If the length of sequence is 1 then is a positive experiment.
		if(length == 1 || (length == 2 && sequence == "78"))
			cout << "+\n";
		// If the first digit is 9 and the last is 4 then is a failed experiment.
		else if(sequence[0] == '9' && sequence[length - 1] == '4')
			cout << "*\n";
		// If the last 2 characters are the sequence 35 is a negative experiment,
		else if(sequence[length - 2] == '3' && sequence[length - 1] == '5')
			cout << "-\n";
		// If the sequence does not match with the previous ones then It is a experiment not complete.
		else
			cout << "?\n";
	}
	return 0;
}
