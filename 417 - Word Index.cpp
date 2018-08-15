/*
*	User: Isanchez_Aguilar
*	Problem: UVA 417 - Word Index
*/
#include <bits/stdc++.h>

using namespace std;

map<string, int> wordIndex;

inline void setWord(char c, int currentLength, string w)
{
	if (currentLength == 0)
	{
		int index = wordIndex.size() + 1;
		wordIndex[w] = index;
		return;
	}

	for (char i = c; i <= 'z'; ++i)
	{
		string currentWord(w);
		currentWord.push_back(i);
		setWord(i + 1, currentLength - 1, currentWord);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string current;

	for (int l = 1; l <= 5; ++l)
	{
		current = "";
		setWord('a', l, current);
	}

	while (cin >> current)
	{
		if (wordIndex.count(current))
			cout << wordIndex[current] << "\n";
		else
			cout << "0\n";
	}

	return 0;
}