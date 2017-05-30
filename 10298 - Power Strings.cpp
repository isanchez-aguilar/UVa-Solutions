/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10298 - Power Strings
*/
#include <bits/stdc++.h>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	// Read while not read a dot.
	while(cin >> s && s[0] != '.')
	{
		// Initialize the variables.
		int i = 1;
		int subString = 1;
		int length = s.length();
		// Whilte the index i is smaller than length search the substring.
		while(i < length)
		{
			// While it is different the comparing then increase the substring.
			while(s[i] != s[i % subString])
				++subString;
			// Increase the index.
			++i;
		}
		// Check the length of maximum substring.
		cout << (length % subString?1:length / subString) << '\n'; 
	}
	return 0;
}