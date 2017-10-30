/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10878 - Decode the tape
*/
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while(getline(cin, s))
	{
		if(s[0] == '|')
		{
			char c = 0;
			int bit = 128;

			for(int i = 1; s[i]; ++i)
			{
				if(s[i] == ' ')
					bit >>= 1;
				else if(s[i] == 'o')
				{
					c += bit;
					bit >>= 1;
				}
			}

			cout << c;
		}
	}

	return 0;
}