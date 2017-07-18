/*
*	User: Isanchez_Aguilar
*	Problem: UVA 123 - Searching Quickly
*/
#include <bits/stdc++.h>

using namespace std;

typedef set<string> ss;
typedef pair<string, string> pss;
typedef multimap<string, string> mss;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	ss ignore;
	mss titleList;

	while(getline(cin, s) && s != "::")
		ignore.insert(s);

	while(getline(cin, s))
	{
		int length = s.size();
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		int i = 0;
		while(i < length)
		{
			int j = i;

			if(isalpha(s[i]))
			{
				string key;

				while(j < length && isalpha(s[j]))
				{
					key += s[j];
					++j;		
				}

				if(!ignore.count(key))
				{
					transform(key.begin(), key.end(), key.begin(), ::toupper);
					string title(s);
					title.replace(i, key.size(), key);
					titleList.insert(pss(key, title));
				}
			}

			i = j + 1;
		}
	}

	for (mss::iterator i = titleList.begin(); i != titleList.end(); ++i)
		cout << i->second << "\n";
	return 0;
}