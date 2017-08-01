/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10035 - Primary Arithmetic
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	int b;
	while(cin >> a >> b && (a || b))
	{
		int r = 0;
		int carry = 0;

		while(a || b)
		{
			r = ((a % 10) + (b % 10) + r) / 10;
			a /= 10;
			b /= 10;
			carry += r; 
		}

		switch(carry)
		{
			case 0:
				cout << "No carry operation.\n";
			break;
			case 1:
				cout << "1 carry operation.\n";
			break;
			default:
				cout << carry << " carry operations.\n";
		}
	}

	return 0;
}