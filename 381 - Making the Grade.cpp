/*
*	User: Isanchez_Aguilar
*	Problem: UVA 381 - Making the Grade
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	cout << "MAKING THE GRADE OUTPUT\n";
	while (n--)
	{
		int people;
		int testsNumber;
		cin >> people >> testsNumber;

		double mean = 0.0;
		int bonus[people];
		double avg[people];
		int absences[people];
		int testResult[testsNumber];

		for (int i = 0; i < people; ++i)
		{
			for (int j = 0; j < testsNumber; ++j)
				cin >> testResult[j];

			cin >> bonus[i] >> absences[i];

			sort(testResult, testResult + testsNumber);
			
			int s = 0;
			avg[i] = 0;
			
			if (testsNumber > 2)
				s = 1;
			
			for (int j = s; j < testsNumber; ++j)
				avg[i] += testResult[j];


			avg[i] /= (testsNumber - s);
			avg[i] = floor(avg[i]);
			mean += avg[i];
		}

		mean /= people;
		double standardDesviation = 0.0;
		
		for (int i = 0; i < people; ++i)
			standardDesviation += (avg[i] - mean) * (avg[i] - mean);

		standardDesviation = sqrt(standardDesviation / people);
		
		if (standardDesviation < 1.0)
			standardDesviation = 1.0;

		for (int i = 0; i < people; ++i)
			avg[i] += (bonus[i] / 2) * 3;

		int grade[people];
		
		for (int i = 0; i < people; ++i)
		{
			if (avg[i] >= mean + standardDesviation)
				grade[i] = 0.0;
			else if (avg[i] >= mean)
				grade[i] = 1.0;
			else if (avg[i] >= mean - standardDesviation)
				grade[i] = 2.0;
			else 
				grade[i] = 3.0;
		}

		double avgGrade = 0.0;

		for (int i = 0; i < people; ++i)
		{
			if (not absences[i])
				--grade[i];
			else 
				grade[i] += absences[i] / 4.0;
			
			// Just can get A or F.
			grade[i] = min(max(grade[i], 0), 4);

			avgGrade += 4 - grade[i];
		}

		cout << fixed << setprecision(1) << avgGrade / people << "\n";

	}
	
	cout << "END OF OUTPUT\n";

	return 0;
}