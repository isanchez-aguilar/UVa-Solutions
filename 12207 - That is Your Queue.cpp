/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12207 - That is Your Queue
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int commands;
	int population;

	while (cin >> population >> commands and (population or commands))
	{
		list<int> hospitalQueue;

		for (int i = 1; i <= min(population, commands); ++i)
		{
			hospitalQueue.push_back(i);
		}
	
		cout << "Case " << ++t << ":\n";

		for (int i = 0; i < commands; ++i)
		{
			char command;
			cin >> command;
			if (command == 'N')
			{
				cout << hospitalQueue.front() << "\n";
				hospitalQueue.push_back(hospitalQueue.front());
				hospitalQueue.pop_front();
			}

			else
			{
				int j;
				cin >> j;
				hospitalQueue.remove(j);

				hospitalQueue.push_front(j);
			}
		}
	}

	return 0;
}