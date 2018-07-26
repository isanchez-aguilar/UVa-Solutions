/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10142 - Australian Voting
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int candidates;
		cin >> candidates;

		cin.ignore();
		map<int, string> nameIndex;
		
		for (int i = 0; i < candidates; ++i)
		{
			string name;
			getline(cin, name);

			nameIndex[i + 1] = name;
		}


		string line;
		vvi optionBallot;
		
		while (getline(cin, line) and line.length())
		{
			optionBallot.push_back(vi());
			vi& option = optionBallot.back();

			istringstream in(line);

			for (int i = 0; i < candidates; ++i)
			{
				int c;
				in >> c;

				option.push_back(c);
			}
		}

		vi bestCandidate;
		bool removed[candidates + 1];
		int people = optionBallot.size();
		memset(removed, false, sizeof removed);

		for (int c = 0; c < candidates; ++c)
		{
			int maxBallots = 0;
			bestCandidate.clear();
			vi ballot(candidates + 1, 0);

			for (int i = 0; i < people; ++i)
			{
				int j = 0;

				while (removed[optionBallot[i][j]])
					++j;

				maxBallots = max(maxBallots, ++ballot[optionBallot[i][j]]);
			}
			
			int minBallots = maxBallots;

			for (int i = 1; i <= candidates; ++i)
			{
				if (maxBallots == ballot[i])
					bestCandidate.push_back(i);
				else if (not removed[i] and ballot[i] < minBallots)
					minBallots = ballot[i];
			}
			
			if (minBallots == maxBallots)
				break;

			for (int i = 1; i <= candidates; ++i)
			{
				if (minBallots == ballot[i])
					removed[i] = true;
			}
		}

		for (int i = 1; i <= candidates; ++i)
		{
			if (not removed[i])
				cout << nameIndex[i] << "\n";
		}

		if (testCases)
			cout << "\n";
	}

	return 0;
}