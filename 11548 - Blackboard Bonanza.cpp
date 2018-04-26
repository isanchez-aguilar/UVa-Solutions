/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11548 - Blackboard Bonanza
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s[70];
	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int n;
		cin >> n;
		
		int maxMatching = 0;

		for (int i = 0; i < n; ++i)
			cin >> s[i];

		for (int i = 0; i < n; ++i)
		{
			string s1;
			string s2;
			for (int j = i + 1; j < n; ++j)
			{

				if (s[i].length() < s[j].length())
				{
					s1 = s[j];
					s2 = s[i];
				}
				else
				{
					s1 = s[i];
					s2 = s[j];	
				}

				for (int k = 0; k < s1.length(); ++k)
				{
					int currentMatching = 0;
					
					for (int l = k; l < s1.length() and l - k  < s2.length(); ++l)
					{
						if (s1[l] == s2[l - k])
							++currentMatching;
					}	

					maxMatching = max(maxMatching, currentMatching);
					currentMatching = 0;
					
					for (int l = k, m = s2.length() - 1; l >= 0 and m  >= 0; --l, --m)
					{
						if (s1[l] == s2[m])
							++currentMatching;
					}	
					
					maxMatching = max(maxMatching, currentMatching);
				}

			}
		}

		cout << maxMatching << "\n";
	}

	return 0;
}