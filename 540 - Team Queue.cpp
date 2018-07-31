/*
*	User: Isanchez_Aguilar
*	Problem: UVA 540 - Team Queue
*/
#include <bits/stdc++.h>

using namespace std;

typedef queue<int> qi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;

	while (cin >> n and n)
	{
		map<int, int> teamId;
		for (int i = 0; i < n; ++i)
		{
			int people;
			cin >> people;

			for (int j = 0; j < people; ++j)
			{		
				int id;
				cin >> id;

				teamId[id] = i;
			}
		}

		deque<int> team;
		string instruction;
		deque<qi> queueTeams;
		
		cout << "Scenario #" << ++t << "\n";

		while (cin >> instruction and instruction[0] != 'S')
		{
			if (instruction[0] == 'E')
			{
				int id;
				cin >> id;
				int currentTeam = teamId[id];

				int i = 0;
				while (i < team.size())
				{
					if (team[i] == currentTeam)
					{
						queueTeams[i].push(id);
						break;
					}

					++i;
				}

				if (i >= team.size())
				{
					qi q;
					q.push(id);
					queueTeams.push_back(q);
					team.push_back(currentTeam);
				}
			}

			else
			{
				cout << queueTeams[0].front() << "\n";
				
				queueTeams[0].pop();

				if (queueTeams[0].empty())
				{
					team.pop_front();
					queueTeams.pop_front();
				}
			}
		}

		cout << "\n";
	}

	return 0;
}