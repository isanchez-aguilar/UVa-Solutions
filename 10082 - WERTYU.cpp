/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10082 - WERTYU
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int t = 0;
	const char leftLetters[] = {'A', 'V', 'X', 'S', 'W', 'D', 'F', 'G', 'U', 'H', 'J', 'K', 'N', 'B', 'I', 'O', 'Q', 'E', 'A', 'R', 'Y', 'C', 'Q', 'Z', 'T', 'Z'};

	while(getline(cin, s))
	{
		if(t++)
			cout << "\n";
		int length = s.length();
		for(int i = 0; i < length; ++i)
		{
			if(isalpha(s[i]))
				cout << leftLetters[s[i] - 'A'];
			else if(isdigit(s[i]))
			{
				if(s[i] == '0')
					cout << "9";
				else if(s[i] == '1')
					cout << "`";
				else
					cout << (char)(s[i] - 1);
			}
			else
			{
				if(s[i] == ' ')
					cout << " ";
				else if(s[i] == '-')
					cout << "0";
				else if(s[i] == '=')
					cout << "-";
				else if(s[i] == '[')
					cout << "P";
				else if(s[i] == ']')
					cout << "[";
				else if(s[i] == '\\')
					cout << "]";
				else if(s[i] == ';')
					cout << "L";
				else if(s[i] == '\'')
					cout << ";";
				else if(s[i] == ',')
					cout << "M";
				else if(s[i] == '.')
					cout << ",";
				else
					cout << ".";
			}
		}
	}

	return 0;
}