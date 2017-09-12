/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10815 - Andy's First Dictionary
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	set<string> dictionary;

	while(cin >> s)
	{
		string word = "";
		int length = s.length();

		for(int i = 0; i < length; ++i)
		{
			char c = tolower(s[i]);
			if(c <= 'z' and c >= 'a')
				word += c;
			
			else if(word != "")
			{
				dictionary.insert(word);
				word = "";				
			}
		}

		if(word != "")
			dictionary.insert(word);

	}

	for(set<string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
		cout << *i << "\n";

	return 0;
}