/*
*	User: Isanchez_Aguilar
*	Problem: UVA 642 - Word Amalgamation
*/
#include <bits/stdc++.h>

using namespace std;

typedef set<string> ss;
typedef map<string, ss> msss;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string input;
	msss dictionary;
	
	while (cin >> input and input[0] != 'X')
	{
		string aux = input;
		sort(input.begin(), input.end());
		dictionary[input].insert(aux);
	}
	
	while (cin >> input and input[0] != 'X')
	{
		sort(input.begin(), input.end());
		if (dictionary.count(input) > 0)
		{
			for (ss::iterator i = dictionary[input].begin(); i != dictionary[input].end(); ++i)
				cout << *i << "\n";
		}
		else
			cout << "NOT A VALID WORD\n";
		
		cout << "******\n";
	}

	return 0;
}
