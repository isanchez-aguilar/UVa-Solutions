/*
*	User: Isanchez_Aguilar
*	Problem: UVA 156 - Ananagrams
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int size = 0;
	vector<string> words;
	map<string, int> frequency;

	while(cin >> s and s != "#")
	{
		++size;
		words.push_back(s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		
		sort(s.begin(), s.end());
		++frequency[s];
	}

	sort(words.begin(), words.end());

	for(int i = 0; i < size; ++i)
	{
		string temp = words[i];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		sort(temp.begin(), temp.end());

		if(frequency[temp] == 1)
			cout << words[i] << "\n";
	}

	return 0;
}