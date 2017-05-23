/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12577 - Hajj-e-Akbar
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the name.
	string name;
	// Variable to know the number of test.
	int i = 1;
	// Read the name.
	cin >> name;
	while(name[0] != '*')
	{
		// If the name is Hajj.
		if(name[0] == 'H')
			cout << "Case " << i++ << ": Hajj-e-Akbar\n";
		// If the name is Umrah.
		else
			cout << "Case " << i++ << ": Hajj-e-Asghar\n";
		// Read the name.
		cin >> name;
	}
	return 0;
}