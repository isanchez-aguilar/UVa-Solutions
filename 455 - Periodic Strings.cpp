/*
*	User: Isanchez_Aguilar
*	Problem: UVA 455 - Periodic Strings
*/
#include <bits/stdc++.h>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int testCases;
	cin >> testCases;
	// Read while testCases is not zero.
	while(testCases--)
	{
		// Read the string.
		cin >> s;
		int i = 1;
		int subString = 1;
		int length = s.length();
		// Check the length of substrings.
		while(i < length)
		{
			// If is diferent the substring then increase the size.
			while(s[i] != s[i % subString])
				++subString;
			// Increase the index of string.
			++i;
		}
		// Increase the minimum length of substring.
		cout << (length % subString?length: subString) << '\n';
		if(testCases)
			cout << '\n';
	}
	return 0;
}