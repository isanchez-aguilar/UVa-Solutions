/*
*	User: Isanchez_Aguilar
*	Problem: UVA 455 - Periodic Strings
*/
#include <bits/stdc++.h>

using namespace std;

inline vector<int> zAlgorithm(const string& s)
{
	const int length = (int)s.length();
	vector<int> z(length);

	for (int i = 1, left = 0, right = 0; i < length; ++i)
	{
		if (i <= right)
			z[i] = min(right - i + 1, z[i - left]);

		while (i + z[i] < length and s[z[i]] == s[i + z[i]])
			++z[i];

		if (right < z[i] + i - 1)
		{
			left = i;
			right = z[i] + i - 1;
		}
	}

	return z;
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

		vector<int> z = zAlgorithm(s);
		const int length = (int)s.length();
		int substringLength = length;

		for (int i = 1; i < length; ++i)
		{
			if (length % i == 0 and z[i] + i == length)
			{
				substringLength = i;
				break;
			}
		}

		cout << substringLength << "\n";

		if (testCases)
			cout << "\n";
	}

	return 0;
}