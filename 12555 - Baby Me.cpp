/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12555 - Baby Me
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	cin >> testCases;
	cin.ignore();
	
	for (int t = 1; t <= testCases; ++t)
	{
		string c;
		double a;
		cin >> a;
		
		getline(cin, c);
		cout << "Case " << t << ": ";

		if (c.length() > 3)
			cout << a * 0.5 + (c[3] - '0') * 0.05 << "\n";
		else
			cout << a * 0.5 << "\n";
	}
	
	return 0;
}
