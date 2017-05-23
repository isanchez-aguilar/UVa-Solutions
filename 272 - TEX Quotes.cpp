/*
*	User: Isanchez_Aguilar
*	Problem: UVA 272 - TEX Quotes
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the read character.
	char character = '\0';
	// Variable to know if they are opening or closing double-quote.
	int opening = 1;
	// Read while not EOF.
	while(cin.get(character))
	{
		// If character read is double-quote.
		if(character == '\"')
		{
			// If double-quote is opening then change by ``.
			if(opening)
				cout << "``";
			// If double-quote is closing then change by ''.
			else
				cout << "''";
			// If double-quote is opening the next going to be closing and vice versa. 
			opening = !opening;
		}
		// If the character read is different from double-quote then only the character is printed.
		else
			cout << character;
	}
	return 0;
}