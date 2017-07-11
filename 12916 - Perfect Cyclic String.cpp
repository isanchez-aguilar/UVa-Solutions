/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12916 - Perfect Cyclic String
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		string s;
		cin >> s;

		int subString = 1;
		int length = s.length();
		for(int j = 1; j < length; ++j)
		{
			while(s[j] != s[j % subString])
				++subString;
		}
		cout << (length % subString?length:subString) << endl;
	}
	return 0;
}