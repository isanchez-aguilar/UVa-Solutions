/*
*	User: Isanchez_Aguilar
*	Problem: UVA 735 - Dart-a-Mania
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<int> scores;
	scores.insert(0);
	for(int i = 1; i <= 20; ++i)
	{
		scores.insert(i);
		scores.insert(i * 2);
		scores.insert(i * 3);
	}
	scores.insert(50);

	int score;
	int index = 0;
	int sizeScores = scores.size();
	vector<int> possibleScores(sizeScores);
	
	for(set<int>::iterator i = scores.begin(); i != scores.end(); ++i)
		possibleScores[index++] = *i;

	while(cin >> score && score > 0)
	{
		set< set<int> > totalCombinations;

		for(int i = 0; i < sizeScores && possibleScores[i] <= score; ++i)
		{
			for(int j = 0; j < sizeScores && possibleScores[j] <= score - possibleScores[i]; ++j)
			{
				for(int k = 0; k < sizeScores && possibleScores[k] <= score - possibleScores[i] - possibleScores[j]; ++k)
				{
					if(possibleScores[i] + possibleScores[j] + possibleScores[k] == score)
					{
						set<int> combination;
						combination.insert(i);
						combination.insert(j);
						combination.insert(k);
						
						totalCombinations.insert(combination);
					}
				}
			}
		}

		int totalPermutations = 0;

		for(set< set<int> >::iterator i = totalCombinations.begin(); i != totalCombinations.end(); ++i)
		{
			if(i->size() == 1)
				++totalPermutations;
			else if(i->size() == 2)
				totalPermutations += 3;
			else if(i->size() == 3)
				totalPermutations += 6;
		}

		if(totalPermutations > 0)
		{
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << totalCombinations.size() << "." << "\n";
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << totalPermutations << "." << "\n";
		}
		else
			cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << "\n";
		cout << "**********************************************************************\n";
	}

	cout << "END OF OUTPUT" << "\n";
	
	return 0;
}