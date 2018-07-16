/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10070 - Leap Year or Not Leap Year and ...
*/
#include <bits/stdc++.h>

#define toDigit(d) d-'0'

using namespace std;

int mod(string number, int n)
{
	int length = number.length();

	int ans = 0;

	for (int i = 0; i < length; ++i)
		ans = ((ans * 10) % n + toDigit(number[i])) % n;

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string number;
	int testCase = 0;

	while (cin >> number)
	{
		if (testCase++)
			cout << "\n";

		bool leapYear = false;
		bool ordinary = true;

		if (mod(number, 400) == 0 or (mod(number, 4) == 0 and mod(number, 100) != 0))
		{
			leapYear = true;
			ordinary = false;

			cout << "This is leap year.\n";
		}

		if (mod(number, 15) == 0)
		{
			ordinary = false;
			cout << "This is huluculu festival year.\n";
		}

		if (leapYear and mod(number, 55) == 0)
				cout << "This is bulukulu festival year.\n";

		if (ordinary)
			cout << "This is an ordinary year.\n";
	}

	return 0;
}