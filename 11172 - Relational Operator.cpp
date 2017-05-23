/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11172 - Relational Operator
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save number of test cases.
	int testCases;
	// Variables to save the numbers to compare.
	int number1;
	int number2;
	// Read the number of test cases.
	cin >> testCases;
	// Read while not EOF.
	while(testCases--)
	{
		// Read two numbers to compare.
		cin >> number1 >> number2;
		// If the number1 is bigger than number 2 then print <. 
		if(number1 < number2)
			cout << "<\n";
		// If the number2 is bigger than number 1 then print >.
		else if(number1 > number2)
			cout << ">\n";
		// If the numbers are equal then print =.
		else
			cout << "=\n";
	}
	return 0;
}