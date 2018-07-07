/*
*	User: Isanchez_Aguilar
*	Problem: UVA 333 - Recognizing Good ISBNs
*/
#include <bits/stdc++.h>

using namespace std;

const string WHITESPACE = "\n\r\t\f\v ";

inline string ltrim(const string& s)
{
	int i = s.find_first_not_of(WHITESPACE);
	return (i == -1?"":s.substr(i));
}

inline string rtrim(const string& s)
{
	int i = s.find_last_not_of(WHITESPACE);
	return (i == -1?"":s.substr(0, i + 1));
}

inline string trim(const string& s)
{
	return rtrim(ltrim(s));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string code;
	while (getline(cin, code))
	{
		code = trim(code);
		vector<int> accumulated(1, 0);
		
		for (int i = 0; i < code.length(); ++i)
		{
			if (isdigit(code[i]))
				accumulated.push_back(accumulated.back() + code[i] - '0');
			else if (accumulated.size() == 10 and code[i] == 'X')
				accumulated.push_back(accumulated.back() + 10);
			else if (code[i] != '-' and code[i] != ' ')
			{
				accumulated.clear();
				break;
			}

		}

		bool correct = false;
		if (accumulated.size() == 11)
		{
			for (int i = 1; i < accumulated.size(); ++i)
				accumulated[i] += accumulated[i - 1];
			
			if (accumulated.back() % 11 == 0)
				correct = true;
		}

		if (correct)
			cout << code << " is correct.\n";
		else
			cout << code << " is incorrect.\n";
	}	

	return 0;
}