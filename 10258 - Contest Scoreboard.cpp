/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10258 - Contest Scoreboard
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Contestant
{
public:
	int id;
	int time;
	int solved;
	vi submissions;
	bitset<10> isSolved;
	Contestant(int _id):id(_id), time(0), solved(0), submissions(vi(10)){}

	inline bool operator<(const Contestant &a)
	{
		if(solved == a.solved)
		{
			if(time == a.time)
				return  (id < a.id);
			return (time < a.time);
		}
		return (solved > a.solved);
	}

};

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
		string submission;
		vector<Contestant> data;
		bitset<101> participation;

		for(int i = 0; i < 101; ++i)
			data.push_back(Contestant(i));

		while(getline(cin, submission) && submission.length() != 0)
		{
			int id;
			int time;
			char status;
			int problem;
			istringstream in(submission);
			
			in >> id >> problem >> time >> status;
			participation[id] = 1;

			if(!data[id].isSolved[problem])
			{
				if(status == 'C')
				{
					++data[id].solved;
					data[id].isSolved[problem] = 1;
					data[id].time += time + data[id].submissions[problem] * 20;
				}
				else if(status == 'I')
					++data[id].submissions[problem];
			}
		}

		vector<Contestant> board;

		for(int i = 1; i < 101; ++i)
		{
			if(participation[i])
				board.push_back(data[i]);
		}

		sort(board.begin(), board.end());

		for(int i = 0; i < board.size(); ++i)
			cout << board[i].id << " " << board[i].solved << " " << board[i].time << "\n";
		
		if(testCases)
			cout << "\n";
	}

	return 0;
}