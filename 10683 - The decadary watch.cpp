/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10683 - The decadary watch
*/
#include <bits/stdc++.h>

#define toDigit(d) d-'0'

using namespace std;

inline int parseInt(string n)
{
	int ans;
	istringstream in(n);
	
	in >> ans;
	
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string data;
	while (cin >> data)
	{
		int h = parseInt(data.substr(0, 2));
		int m = parseInt(data.substr(2, 2));
		int s = parseInt(data.substr(4, 2));
		int c = parseInt(data.substr(6, 2));

		long long milliseconds = h * 3600000LL + m * 60000LL + s * 1000LL + c * 10;

		h = milliseconds / 8640000LL;
		milliseconds %= 8640000LL;

		m = milliseconds / 86400LL;
		milliseconds %= 86400LL;

		s = milliseconds / 864;
		milliseconds %= 864;

		c = milliseconds * 100 / 864;

		cout << h << setw(2) << setfill('0') << m << setw(2) << setfill('0') << s << setw(2) << setfill('0') << c << "\n";
	}

	return 0;
}