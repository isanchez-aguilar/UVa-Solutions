/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11835 - Formula 1
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int pilots;
	int grandPrix;
	while(cin >> grandPrix >> pilots && (grandPrix || pilots))
	{
		vector< vector<int> > grandPrixPos(grandPrix, vector<int>(pilots));

		for(int i = 0; i < grandPrix; ++i)
		{
			for(int j = 0; j < pilots; ++j)
			{
				int position;
				cin >> position;
				grandPrixPos[i][position - 1] = j;
			}
		}

		int scoreSystems;
		cin >> scoreSystems;

		for(int i = 0; i < scoreSystems; ++i)
		{
			int places;
			cin >> places;
			int maxPoints = -1;
			vector<int> pilotsData(pilots, 0); 

			for(int j = 0; j < places; ++j)
			{
				int points;
				cin >> points;
				for(int k = 0; k < grandPrix; ++k)
				{
					int l = grandPrixPos[k][j];
					pilotsData[l] += points;
					maxPoints = max(maxPoints, pilotsData[l]);
				}
			}

			int size = 0;
			vector<int> board;
			for(int j = 0; j < pilots; ++j)
			{
				if(maxPoints == pilotsData[j])
				{
					++size;
					board.push_back(j + 1);
				}
			}

			for(int j = 0; j < size; ++j)
			{
				cout << board[j];
				if(j < size - 1)
					cout << " ";
			}
			cout << "\n";
		}

	}
	return 0;
}