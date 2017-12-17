/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10945 - Mother bear
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while(getline(cin, s) and s != "DONE")
	{
		string s1("");

		for(int i = 0; i < s.length(); ++i)
		{
			if(isalpha(s[i]))
				s1 += tolower(s[i]);
		}

		int i = 0;
		int j = s1.length() - 1;
		bool isPalindrome = true;
		while(i < j)
		{
			if(s1[i++] != s1[j--])
			{
				isPalindrome = false;
				break;
			}
		}

		if(isPalindrome)
			cout << "You won't be eaten!\n";
		else
			cout << "Uh oh..\n";
	}

	return 0;
}