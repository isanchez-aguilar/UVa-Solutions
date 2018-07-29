/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10698 - Football Sort
*/
#include <bits/stdc++.h>

using namespace std;

class Team
{
public:
	int wins;
	int goals;
	int points;
	string name;
	int gamesPlayed;
	int goalsAgainst;
	int goalsDifference;
	
	Team()
	{}
	Team(string _name)
	{
		wins = 0;
		goals = 0;
		points = 0;
		name = _name;
		gamesPlayed = 0;
		goalsAgainst = 0;
		goalsDifference = 0;
	}

	inline bool operator<(const Team& a)
	{
		if (points == a.points)
		{
			if (goalsDifference == a.goalsDifference)
			{
				if (goals == a.goals)
				{
					int i = 0;
					int j = 0;

					while (i < name.length() and j < a.name.length())
					{
						if (tolower(name[i]) < tolower(a.name[j]))
							return true;

						if (tolower(name[i++]) > tolower(a.name[j++]))
							return false;
					}

					return i < j;
				}

				return goals > a.goals;
			}

			return goalsDifference > a.goalsDifference;
		}

		return points > a.points;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int teams;
	int games;

	while (cin >> teams >> games and (teams or games))
	{
		Team standing[teams];
		map<string, int> indexName;

		for (int i = 0; i < teams; ++i)
		{
			string name;

			cin >> name;
			indexName[name] = i;
			standing[i] = Team(name);
		}

		for (int i = 0; i < games; ++i)
		{
			int goalsA;
			int goalsB;
			string teamA;
			string teamB;

			cin >> teamA >> goalsA;
			cin.ignore(1, '-');
			cin >> goalsB >> teamB;

			int iA = indexName[teamA];
			int iB = indexName[teamB];


			++standing[iA].gamesPlayed;
			++standing[iB].gamesPlayed;
			standing[iA].goals += goalsA;
			standing[iB].goals += goalsB;
			standing[iA].goalsAgainst += goalsB;
			standing[iB].goalsAgainst += goalsA;
			standing[iA].goalsDifference += (goalsA - goalsB);
			standing[iB].goalsDifference += (goalsB - goalsA);

			int pointsA = 0;
			int pointsB = 0;

			if (goalsA < goalsB)
			{
				pointsB = 3;
				++standing[iB].wins;
			}
			
			else if (goalsB < goalsA)
			{	
				pointsA = 3;
				++standing[iA].wins;
			}
			
			else
			{
				pointsA = 1;
				pointsB = 1;	
			}

			standing[iA].points += pointsA;		
			standing[iB].points += pointsB;	
		}

		sort(standing, standing + teams);
		
		if (t++)
			cout << "\n";

		for (int i = 0; i < teams; ++i)
		{
			if (i == 0 or standing[i].points != standing[i - 1].points or standing[i].goalsDifference != standing[i - 1].goalsDifference or standing[i].goals != standing[i - 1].goals)
				cout << setw(2) << i + 1 << ". ";
			else
				cout << "    ";

			cout << setw(15) << standing[i].name << " " << setw(3) << standing[i].points;
			cout << " " << setw(3) << standing[i].gamesPlayed << " " << setw(3) << standing[i].goals;
			cout << " " << setw(3) << standing[i].goalsAgainst << " " << setw(3) << standing[i].goalsDifference;

			if (standing[i].gamesPlayed > 0)
				cout << setprecision(2) << fixed << " " << setw(6) << (double)standing[i].points * 100.00 / (standing[i].gamesPlayed * 3.00);
			else
				cout << "    N/A";

			cout << "\n";
		}
	}

	return 0;
}