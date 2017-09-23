/*
*	User: Isanchez_Aguilar
*	Problem: UVA 494 - Kindergarten Counting Game
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while(getline(cin, s))
	{
		int words = 0;
		string current = "";
		int length = s.length();

		for(int i = 0; i < length; ++i)
		{
			if(isalpha(s[i]))
				current += s[i];
			else
			{
				if(current.length())
					++words;
				
				current = "";
			}
		}

		cout << words << "\n";
	}

	return 0;
}