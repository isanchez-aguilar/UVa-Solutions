/*
*	User: Isanchez_Aguilar
*	Problem: UVA 353 - Pesky Palindromes
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;

	while (cin >> s)
	{
		set<string> palindromes;
		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = 0; j < s.length(); ++j)
			{
				int l = min(i, j);
				int r = max(i, j);
				bool isPalindrome = true;

				while (l < r)
				{
					if (s[l++] != s[r--])
					{

						isPalindrome = false;
						break;
					}
				}

				if (isPalindrome)
					palindromes.insert(s.substr(min(i, j), max(i, j) - min(i, j) + 1));
			}
		}

		cout << "The string \'" << s << "\' contains " << palindromes.size() << " palindromes.\n";
	}

	return 0;
}