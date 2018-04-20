/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10174 - Couple-Bachelor-Spinster Numbers.
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string input;
	while (getline(cin, input))
	{
		long a;
		long b;
		istringstream in(input);
		
		in >> a;
		
		if (in >> b)
		{
			int bachelor = 0;
			
			while (a <= b)
			{
				if ((a & 3L) == 2)
					++bachelor;
				
				++a;
			}
			
			cout << bachelor << "\n";
		}
		else
		{
			bool isPositive = a > 0;
			a *= (isPositive?1L:-1L);
			
			if ((a & 3L) == 2)
			{
				cout << "Bachelor Number.\n";
				continue;
			}
			
			long c;
	
			if (a == 0)
			{
				b = 0;
				c = 0;
			}
			
			else if (a & 1L)
			{
				b = (a - 1) >> 1;
				c = b + 1;
			}
			else
			{
				b = (a >> 2L) - 1;
				c = (a >> 2L) + 1;
			}
			
			if (isPositive)
				cout << c << " " << b << "\n";
			else
				cout << b << " " << c << "\n";
		}
	}
	
	return 0;
}
