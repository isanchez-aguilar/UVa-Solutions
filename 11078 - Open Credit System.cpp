/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11078 - Open Credit System
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int students;
		cin >> students;

		vector<int> score(students);

		for (int i = 0; i < students; ++i)
			cin >> score[i];

		int maxDifference = INT_MIN;
		int minScoreOfStudent = score[students - 1];

		for (int i = students - 2; i >= 0; --i)
		{
			maxDifference = max(maxDifference, score[i] - minScoreOfStudent);
			minScoreOfStudent = min(minScoreOfStudent, score[i]);
		}

		cout << maxDifference << "\n";
	}

	return 0;
}