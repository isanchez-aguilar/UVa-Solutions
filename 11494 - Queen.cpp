/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11494 - Queen
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x1;
	int y1;
	int x2;
	int y2;

	while(cin >> x1 >> y1 >> x2 >> y2 && x1 && y1 && x2 && y2)
	{

		if(x1 == x2)
		{
			if(y1 == y2)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if(y1 == y2)
		{
			if(x1 == x2)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else
		{	
			int deltaX = abs(x1 - x2);
			int deltaY = abs(y1 - y2);
			if(deltaX == deltaY)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
	}
	return 0;
}
