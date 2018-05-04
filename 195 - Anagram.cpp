/*
*	User: Isanchez_Aguilar
*	Problem: UVA 195 - Anagram
*/
#include <bits/stdc++.h>

using namespace std;

inline bool cmp(char a, char b)
{
	if (isupper(a))
	{
		if (isupper(b))
			return a < b;

		return a <= toupper(b);
	}

	if (islower(b))
		return a < b;

	return toupper(a) < b;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end(), cmp);

		do
		{
			cout << s << "\n";
		}while (next_permutation(s.begin(), s.end(), cmp));
	}

	return 0;
}