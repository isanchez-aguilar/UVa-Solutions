/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11192 - Group Reverse
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int multiple;
	while(cin >> multiple && multiple)
	{
		string s;
		cin >> s;
		int divisions = s.length() / multiple;
		
		for(int i = 0; i < multiple; ++i)
			reverse(s.begin() + i * divisions, s.begin() + (i + 1) * divisions);

		cout << s << "\n";
	}

	return 0;
}