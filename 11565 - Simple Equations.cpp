/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11565 - Simple Equations
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int a;
		int b;
		int c;
		bool solution = 0;

		cin >> a >> b >> c;
		for(int x = -22; x < 23; ++x)
		{
			if(x * x <= c)
			{
				for(int y = -100; y < 101 && !solution; ++y)
				{
					if(x != y && x * x + y * y <= c)
					{
						for(int z = -100; z < 101; ++z)
						{
							if(x != z && y != z && x + y + z == a && x * y * z == b && x * x + y * y + z * z == c)
							{
								solution = 1;
								cout << x << " " << y << " " << z << "\n";
								break;
							}
						}
					}
				}
			}
		}
		if(!solution)
			cout << "No solution.\n";
	}

	return 0;
}