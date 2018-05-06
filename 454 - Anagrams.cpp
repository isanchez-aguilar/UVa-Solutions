/*
*	User: Isanchez_Aguilar
*	Problem: UVA 454 - Anagrams
*/
#include <bits/stdc++.h>

using namespace std;

inline string removeSpaces(string s)
{
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	return s;
}

inline bool areEqual(string s1, string s2)
{
	s1 = removeSpaces(s1);
	s2 = removeSpaces(s2);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	cin.ignore();
	cin.ignore();
	while (testCases--)
	{
		string s;
		vector<string> words;

		while (getline(cin, s) and s.length())
			words.push_back(s);

		sort(words.begin(), words.end());

		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = i + 1; j < words.size(); ++j)
			{
				if (areEqual(words[i], words[j]))
					cout << words[i] << " = " << words[j] << "\n";
			}
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}