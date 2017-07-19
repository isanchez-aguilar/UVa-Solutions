/*
*	User: Isanchez_Aguilar
*	Problem: UVA 790 - Head Judge Headache
*/
#include <bits/stdc++.h>

using namespace std;

class Problem
{
public:
	int time;
	bool status;

	Problem(int _time, bool _status):time(_time), status(_status){}

	inline bool operator<(const Problem &a)
	{
		if(time == a.time)
			return !status;
		return time < a.time;
	}
};

class Team
{
public:
	int id;
	int time;
	int solved;
	vector< vector<Problem> > problems;

	Team(int _id):id(_id), solved(0), time(0), problems(vector< vector<Problem> >(26)){};
	
	inline void calculateTime()
	{
		for(int i = 0; i < 26; ++i)
		{
			int size = problems[i].size();
			
			if(size)
			{
				sort(problems[i].begin(), problems[i].end());
				
				vector<int> wrong(size, 0);
				if(problems[i][0].status)
				{
					++solved;
					time += problems[i][0].time;
				}
				else
				{
					wrong[0] = 1;
					for(int j = 1; j < size; ++j)
					{
						if(problems[i][j].status)
						{
							++solved;
							time += problems[i][j].time + wrong[j - 1] * 20;
							break;
						}
						else
							wrong[j] = wrong[j - 1] + 1;
					}
				}
			}
		}
	}

	inline bool operator<(const Team &a)
	{
		if(solved == a.solved)
		{
			if(time == a.time)
				return id < a.id;		
			
			return time < a.time;
		}
		return solved > a.solved;
	}
};


inline int getTime(char time[])
{
	if(strlen(time) == 5)
		return (atoi(time) * 60 + atoi(time + 3));
	return (atoi(time) * 60 + atoi(time + 2));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCases;
	cin >> testCases;
	
	cin.ignore();
	cin.ignore();
	while(testCases--)
	{
		int id;
		vector<Team> contest;
		bitset<26> participation;
		
		for(int i = 0; i < 27; ++i)
			contest.push_back(Team(i));
		
		string data;
		while(getline(cin, data) && data.length() != 0)
		{
			int id;
			char time[6];
			char problem;
			char statusSubmission;
			istringstream in(data);
			
			in >> id >> problem >> time >> statusSubmission;
			
			participation[id] = 1;

			int idP = problem - 'A';
			if(statusSubmission == 'Y')
				contest[id].problems[idP].push_back(Problem(getTime(time), 1));
			else
				contest[id].problems[idP].push_back(Problem(getTime(time), 0));
		}

		vector<Team> board;
		for(int i = 1; i < 27; ++i)
		{
			if(participation[i])
			{
				contest[i].calculateTime();
				board.push_back(contest[i]);
			}
		}

		sort(board.begin(), board.end());
		
		int maxTeam = 0;
		int size = size = board.size();
		
		cout << "RANK TEAM PRO/SOLVED TIME\n";
		int rank = 0;
		int place = 0;
		for(int i = 0; i < size; ++i)
		{
			maxTeam = max(maxTeam, board[i].id);
			if(board[i].solved)
			{
				++place;
				if(i && board[i - 1].time == board[i].time && board[i - 1].solved == board[i].solved)
					cout << setw(4) << rank << " ";
				else
				{
					rank = i + 1;
					cout << setw(4) << rank << " ";
				}

				cout << setw(4) << board[i].id;

					cout << setw(5) << board[i].solved << setw(11) << board[i].time; 
				cout << "\n";
			}
		}
		rank = place + 1;
		for(int i = 1; i <= maxTeam; ++i)
		{
			if(contest[i].solved == 0)
			{
				cout << setw(4) << rank << " " << setw(4) << i << "\n";
			}
		}
		if(testCases)
			cout << "\n";
	}
	return 0;
}