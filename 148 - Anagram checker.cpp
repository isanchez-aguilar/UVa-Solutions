/*
*	User: Isanchez_Aguilar
*	Problem: UVA 148 - Anagram checker
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;

string w;
vb added;
vb available;
vs dictionary;
vvi frequency;

inline vi getFrequency(string s)
{
	vi f(26);
	
	for (int i = 0; i < s.length(); ++i)
	{
		if (isalpha(s[i]	))
			++f[s[i] - 'A'];
	}
	return f;
}

inline void setAvaiables()
{
	string s;
	istringstream in(w);
	available.assign(dictionary.size(), true);
	
	while (in >> s)
	{
		for (int i = 0; i < dictionary.size(); ++i)
		{
			if (s == dictionary[i])
				available[i] = false;
		}
	}
	
	return;
}

inline void findAnagrams(vi f, vs words, int index)
{
	bool complete = true;
	
	for (int i = 0; i < 26; ++i)
	{
		int difference = f[i] - frequency[index][i];
		
		if (difference < 0)
			return;
		
		if (difference)
			complete = false;
			
		f[i] = difference;
	}
		
	if (complete)
	{
		cout << w << " = ";
		for (int i = 0; i < added.size(); ++i)
		{
			if (added[i])
				cout << dictionary[i] << " ";
		}		
		cout << dictionary[index] << "\n";
	}
	else
	{
		added[index] = true;
		for (int i = index + 1; i < dictionary.size(); ++i)
		{
			if (available[i])
				findAnagrams(f, words, i);
		}
		added[index] = false;
	}
	
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin >> w and w != "#")
		dictionary.push_back(w);
	
	sort(dictionary.begin(), dictionary.end());
	
	frequency.resize(dictionary.size());
	
	for (int i = 0; i < dictionary.size(); ++i)
		frequency[i] = getFrequency(dictionary[i]);
	
	cin.ignore();
	while (getline(cin, w) and w != "#")
	{
		setAvaiables();
		added.resize(dictionary.size());
		vi wordFrequency = getFrequency(w);
		
		for (int i = 0; i < dictionary.size(); ++i)
		{
			if (available[i])
				findAnagrams(wordFrequency, vs(), i);
		}
	}

	return 0;
}
