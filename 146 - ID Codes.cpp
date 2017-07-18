/*
*	User: Isanchez_Aguilar
*	Problem: UVA 146 - ID Codes
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while(cin >> s && s != "#")
	{
		if(next_permutation(s.begin(), s.end()))
			cout << s << "\n";
		else
			cout << "No Successor\n";
	}

	return 0;
}