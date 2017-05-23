/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11727 - Cost Cutting
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
	for(int i = 1; i <= testCases; ++i)
	{
		// Print the number of test case.
		cout << "Case " << i << ": ";
		// Variables to save the 3 values.
		int a;
		int b;
		int c;
		// Read the first 2 values.
		cin >> a;
		cin >> b;
		// If b is bigger than a then the maximum is c = b.
		if(a < b)
			c = b;
		// If a is bigger than b then the maximum is c = a.
		else
		{
			c = a;
			a = b;
		}
		// Read the third value.
		cin >> b;
		// If b is greater than c, then b is the maximum and c is the middle value.
		if(b > c)
			cout << c << "\n";
		// If b is lesser than a, then b is the minimum and a is the middle value.
		else if(b < a)
			cout << a << "\n";
		// If b is not greater than c and lesser than a then b is the middle value.
		else
			cout << b << "\n";
	}
	return 0;
}