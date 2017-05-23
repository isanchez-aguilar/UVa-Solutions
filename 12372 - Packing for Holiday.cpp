/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12372 - Packing for Holiday
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
	// Read the test cases.
	for(int i = 1; i <= testCases; ++i)
	{
		// Print the number of test case.
		cout << "Case " << i << ": ";
		// Variable to save the dimensions of box.
		int length;
		int width;
		int height;
		// Read the dimensions of box.
		cin >> length >> width >> height;
		// If all sides are lesser than 20 then It's ok.
		if(length <= 20 && width <= 20 && height <= 20)
			cout << "good\n";
		// If is bigger than his bag.
		else
			cout << "bad\n";
	}
	return 0;
}