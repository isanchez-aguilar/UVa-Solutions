/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10018 - Reverse and Add
*/
#include <bits/stdc++.h>

using namespace std;

inline bool isPalindrome(long long n)
{
	ostringstream out;
	out << n;
	string number = out.str();

	int l = 0;
	int r = number.length() - 1;

	while (l < r)
	{
		if (number[l++] != number[r--])
			return false;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		long long n;
		cin >> n;
		int iterations = 0;
		do
		{	
			ostringstream out;

			out << n;
			
			string nInverse = out.str();
			reverse(nInverse.begin(), nInverse.end());

			long long n1;
			istringstream in(nInverse);
			in >> n1;
			n += n1;
			++iterations;
		}
		while (not isPalindrome(n));

		cout << iterations << " " << n << "\n";
	}

	return 0;
}