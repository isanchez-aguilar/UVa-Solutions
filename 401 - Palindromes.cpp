/*
*	User: Isanchez_Aguilar
*	Problem: UVA 401 - Palindromes
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	char key[91];

	key['A'] = 'A';
	key['E'] = '3';
	key['H'] = 'H';
	key['I'] = 'I';
	key['J'] = 'L';
	key['L'] = 'J';
	key['M'] = 'M';
	key['O'] = 'O';
	key['S'] = '2';
	key['T'] = 'T';
	key['U'] = 'U';
	key['V'] = 'V';
	key['W'] = 'W';
	key['X'] = 'X';
	key['Y'] = 'Y';
	key['Z'] = '5';
	key['1'] = '1';
	key['2'] = 'S';
	key['3'] = 'E';
	key['5'] = 'Z';
	key['8'] = '8';

	while(cin >> s)
	{
		string mirror = "";
		string reverse = "";
		int length = s.length();

		for(int i = length - 1; i > -1; --i)
		{
			reverse += s[i];
			mirror += key[s[i]];
		}

		if(s == reverse)
		{
			if(s == mirror)
				cout << s << " -- is a mirrored palindrome.\n\n";
			else
				cout << s << " -- is a regular palindrome.\n\n";
		}
		else
		{
			if(s == mirror)
				cout << s << " -- is a mirrored string.\n\n";
			else
				cout << s << " -- is not a palindrome.\n\n";
		}
	}

	return 0;
}