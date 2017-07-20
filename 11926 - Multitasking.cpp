/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11926 - Multitasking
*/
#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	int n;
	bitset<MAX> calendar;
	while(cin >> n >> m && (n || m))
	{
		int a;
		int b;
		int period;
		bool conflict = 0;
		calendar.reset();

		for(int i = 0; i < n; ++i)
		{
			cin >> a >> b;

			if(!conflict)
			{
				for(int j = a; j < b; ++j)
				{
					if(calendar[j])
					{
						conflict = 1;
						break;
					}
					calendar[j] = 1;
				}
			}
		}

		for(int i = 0; i < m; ++i)
		{
			cin >> a >> b >> period;

			if(!conflict)
			{
				while(a < MAX)
				{
					for(int j = a; j < b && j < MAX; ++j)
					{
						if(calendar[j])
						{
							conflict = 1;
							break;
						}
						calendar[j] = 1;
					}
					a += period;
					b += period;
				}
			}
		}

		if(conflict)
			cout << "CONFLICT\n";
		else
			cout << "NO CONFLICT\n";
	}

	return 0;
}