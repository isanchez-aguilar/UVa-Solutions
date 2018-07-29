/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10194 - Football (aka Soccer)
*/
#include <bits/stdc++.h>

using namespace std;

class Team
{
public:
	int wins;
	int ties;
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
		ties = 0;
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
			if (wins == a.wins)
			{
				if (goalsDifference == a.goalsDifference)
				{
					if (goals == a.goals)
					{
						if (gamesPlayed == a.gamesPlayed)
						{
							int i = 0;
							int j = 0;
							//cout << a.name << endl;
							while (i < name.length() and j < a.name.length())
							{
								if (tolower(name[i]) < tolower(a.name[j]))
									return true;

								if (tolower(name[i++]) > tolower(a.name[j++]))
									return false;
								//cout << name[i - 1] << " " << a.name[j - 1] << endl;
							}

							return i < j;
						}

						return gamesPlayed < a.gamesPlayed;
					}

					return goals > a.goals;
				}

				return goalsDifference > a.goalsDifference;
			}

			return wins > a.wins;
		}

		return points > a.points;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	string team[30];

	cin >> testCases;
	cin.ignore();

	while (testCases--)
	{

		string tournament;
		getline(cin, tournament);

		int numberTeams;
		cin >> numberTeams;

		cin.ignore();
		map<string, int> indexName;
		Team standing[numberTeams];

		for (int i = 0; i < numberTeams; ++i)
		{
			string name;
			getline(cin, name);

			team[i] = name;
			indexName[name] = i;
			standing[i] = Team(name);
		}

		int stands;
		cin >> stands;

		cin.ignore();
		for (int i = 0; i < stands; ++i)
		{
			string game;
			getline(cin, game);

			int goalsA;
			int goalsB;
			string teamA;
			string teamB;
			istringstream in(game);

			getline(in, teamA, '#');
			
			in >> goalsA;
			in.ignore(1, '@');
			
			in >> goalsB;
			in.ignore(1, '#');

			getline(in, teamB);

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
				++standing[iA].ties;		
				++standing[iB].ties;		
			}

			standing[iA].points += pointsA;		
			standing[iB].points += pointsB;	
		}

		sort(standing, standing + numberTeams);

		cout << tournament << "\n";

		for (int i = 0; i < numberTeams; ++i)
		{
			cout << i + 1 << ") " << standing[i].name << " " << standing[i].points << "p, " << standing[i].gamesPlayed << "g (";
			cout << standing[i].wins << "-" << standing[i].ties << "-" << standing[i].gamesPlayed - standing[i].wins - standing[i].ties;
			cout << "), " << standing[i].goalsDifference << "gd (" << standing[i].goals << "-" << standing[i].goalsAgainst << ")\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}