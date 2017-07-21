/*
*	User: Isanchez_Aguilar
*	Problem: UVA 732 - Anagrams by Stack
*/
#include <bits/stdc++.h>

using namespace std;

string word;
string anagram;
int length = 0;

inline void searchActions(int actionsNumber, string anagram1, string word1, string stack, string actions)
{
	if(actionsNumber == (length << 1))
	{
		if(anagram1 == anagram)
			cout << actions << "\n";
		return;
	}

	if(word1.length())
		searchActions(actionsNumber + 1, anagram1, word1.substr(1, word1.length() - 1), stack + word1[0], actions + (actionsNumber?" i":"i"));
	
	int l = stack.length();
	if(l && stack[l - 1] == anagram[anagram1.length()])
	{
		searchActions(actionsNumber + 1, anagram1 + stack[l - 1], word1, stack.substr(0, l - 1), actions + " o");
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> word >> anagram)
	{
		length = word.length();

		cout << "[\n";
		if(length == anagram.length())		
			searchActions(0, "", word, "", "");
		
		cout << "]\n";
	}
	return 0;
}