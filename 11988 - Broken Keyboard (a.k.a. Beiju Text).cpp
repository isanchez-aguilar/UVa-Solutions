/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11988 - Broken Keyboard (a.k.a. Beiju Text)
*/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string text;
	while(cin >> text)
	{
		list<char> monitorText;
		list<char>::iterator j = monitorText.end();
		int length = text.length();
		
		for(int i = 0; i < length; ++i)
		{
			switch(text[i])
			{
				case '[':
					j = monitorText.begin();
				break;
				case ']':
					j = monitorText.end();
				break;
				default:
					monitorText.insert(j, text[i]);
			}
		}

		for(list<char>::iterator i = monitorText.begin(); i != monitorText.end(); ++i)
			cout << *i;
		cout << "\n";
	}

	return 0;
}
