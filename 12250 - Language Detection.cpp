/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12250 - Language Detection
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to know the current number of test case.
	int i = 1;
	// Variable to save the greeting.
	string greeting;
	// Read the word while is different from #.
	while(cin >> greeting && greeting[0] != '#')
	{
		// If the first letter is H then compare with greetings beggining whit H.
		if(greeting[0] == 'H')
		{
			// If the greeting is in Spanish.
			if(greeting == "HOLA")
				cout << "Case " << i++ << ": SPANISH\n";
			// If the greeting is in German.
			else if(greeting == "HALLO")
				cout << "Case " << i++ << ": GERMAN\n";
			// If the greeting is in English.
			else if(greeting == "HELLO")
				cout << "Case " << i++ << ": ENGLISH\n";
			// If the greeting is in Unknown.
			else
				cout << "Case " << i++ << ": UNKNOWN\n";
		}
		// If the greeting is in Italian.
		else if(greeting == "CIAO")
			cout << "Case " << i++ << ": ITALIAN\n";
		// If the greeting is in French.
		else if(greeting == "BONJOUR")
			cout << "Case " << i++ << ": FRENCH\n";
		// If the greeting is in Russian.
		else if(greeting == "ZDRAVSTVUJTE")
			cout << "Case " << i++ << ": RUSSIAN\n";
		// If the greeting is in Unkown.
		else
			cout << "Case " << i++ << ": UNKNOWN\n";	
	}
	return 0;
}	