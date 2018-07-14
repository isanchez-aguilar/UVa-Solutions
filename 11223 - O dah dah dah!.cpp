/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11223 - O: dah dah dah!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<string, char> morseCode;
	morseCode[".-"] = 'A';
	morseCode["-..."] = 'B';
	morseCode["-.-."] = 'C';
	morseCode["-.."] = 'D';
	morseCode["."] = 'E';
	morseCode["..-."] = 'F';
	morseCode["--."] = 'G';
	morseCode["...."] = 'H';
	morseCode[".."] = 'I';
	morseCode[".---"] = 'J';
	morseCode["-.-"] = 'K';
	morseCode[".-.."] = 'L';
	morseCode["--"] = 'M';
	morseCode["-."] = 'N';
	morseCode["---"] = 'O';
	morseCode[".--."] = 'P';
	morseCode["--.-"] = 'Q';
	morseCode[".-."] = 'R';
	morseCode["..."] = 'S';
	morseCode["-"] = 'T';
	morseCode["..-"] = 'U';
	morseCode["...-"] = 'V';
	morseCode[".--"] = 'W';
	morseCode["-..-"] = 'X';
	morseCode["-.--"] = 'Y';
	morseCode["--.."] = 'Z';
	morseCode["-----"] = '0';
	morseCode[".----"] = '1';
	morseCode["..---"] = '2';
	morseCode["...--"] = '3';
	morseCode["....-"] = '4';
	morseCode["....."] = '5';
	morseCode["-...."] = '6';
	morseCode["--..."] = '7';
	morseCode["---.."] = '8';
	morseCode["----."] = '9';
	morseCode[".-.-.-"] = '.';
	morseCode["--..--"] = ',';
	morseCode["..--.."] = '?';
	morseCode[".----."] = '\'';
	morseCode["-.-.--"] = '!';
	morseCode["-..-."] = '/';
	morseCode["-.--."] = '(';
	morseCode["-.--.-"] = ')';
	morseCode[".-..."] = '&';
	morseCode["---..."] = ':';
	morseCode["-.-.-."] = ';';
	morseCode["-...-"] = '=';
	morseCode[".-.-."] = '+';
	morseCode["-....-"] = '-';
	morseCode["..--.-"] = '_';
	morseCode[".-..-."] = '"';
	morseCode[".--.-."] = '@';

	int testCases;
	cin >> testCases;
	
	cin.ignore();

	for (int t = 1; t <= testCases; ++t)
	{
		if (t > 1)
			cout << "\n";

		cout << "Message #" << t << "\n";

		string line;
		getline(cin, line);

		int i = 0;
		string word;
		istringstream in(line);
		
		while (getline(in, word, ' '))
		{
			if (word.length() == 0)
				cout << " ";

			else
				cout << morseCode[word];
		}

		cout << "\n";
	}

	return 0;
}