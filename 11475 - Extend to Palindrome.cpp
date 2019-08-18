/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11475 - Extend to Palindrome
*/
#include <bits/stdc++.h>

using namespace std;

inline void manacher(const string& s, vector<int>& lengthOddPal, vector<int>& lengthEvenPal)
{
	const int n = s.length();

	lengthOddPal.resize(n);
	lengthEvenPal.resize(n);

	// lengthOddPal[i] is odd length of palindrome with center in i.

	for (int i = 0, l = 0, r = -1; i < n; ++i)
	{
		int k = (i > r?1: min(lengthOddPal[l + r - i], r - i + 1));
		
		while (k <= i and i + k < n and s[i - k] == s[i + k])
			++k;

		lengthOddPal[i] = k--;
		
		if (r < i + k)
		{
			l = i - k;
			r = i + k;
		}
	}

	// lengthOddPal[i] is even length of palindrome with center in i and i - 1.
	
	for (int i = 0, l = 0, r = -1; i < n; ++i)
	{
		int k = (i > r?0:min(lengthEvenPal[l + r - i + 1], r - i + 1));

		while (0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k])
			++k;

		lengthEvenPal[i] = k--;
		
		if (r < i + k)
		{
			l = i - k - 1;
			r = i + k ;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	vector<int> d1, d2;

	while (cin >> s)
	{
		manacher(s, d1, d2);

		int maxLength = 0;
		const int n = s.length();

		for (int i = 0; i < n; ++i)
		{
			if (d1[i] + i == n and maxLength < 1 + (d1[i] - 1))
				maxLength =  1 + 2 * (d1[i] - 1);

			if (d2[i] + i == n and maxLength < 2 * d2[i])
				maxLength = 2 * d2[i];
		}

		cout << s;

		for (int i = n - maxLength - 1; i >= 0; --i)
			cout << s[i];

		cout << "\n";
	}

	return 0;
}