/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10055 - Hashmat the Brave Warrior
*/
#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Data about armies.
	unsigned long army1;
	unsigned long army2;
	// Read while not EOF.
	while(cin >> army1 >> army2)
	{
		switch(army1 < army2)
		{
			case 1:
				cout << army2 - army1 << '\n';
				break;
			default:
				cout << army1 - army2 << '\n';
		}
	}
	return 0;
}