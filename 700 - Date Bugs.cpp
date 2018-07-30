/*
*	User: Isanchez_Aguilar
*	Problem: UVA 700 - Date Bugs
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int computers;
	bool available[10000];

	while (cin >> computers and computers)
	{
		memset(available, true, sizeof available);


		for (int i = 0; i < computers; ++i)
		{
			int y;
			int a;
			int b;
			cin >> y >> a >> b;
			
			for (int i = 0; i < y; ++i)
				available[i] = false;
			
			for (int i = (y + 1); i < 10000; ++i)
			{
				if ((i - y) % (b - a) != 0)
					available[i] = false;
			}
		}

		bool bug = false;

		cout << "Case #" << ++t << ":\n";
		
		for (int i = 0; i < 10000; ++i)
		{
			if (available[i])
			{
				bug = true;
				cout << "The actual year is " << i << ".\n";
				break;
			}
		}

		if (not bug)
			cout << "Unknown bugs detected.\n";
		
		cout << "\n";
	}

	return 0;
}