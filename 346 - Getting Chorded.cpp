/*
*	User: Isanchez_Aguilar
*	Problem: UVA 346 - Getting Chorded
*/
#include <bits/stdc++.h>

using namespace std;

inline string getChord(vector<string> &a)
{
	string chord = "";
	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); ++i)
		chord += a[i];

	return chord;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> combination(3);
	map<string, string> majorChord;
	map<string, string> minorChord;

	const string note[][12] = {
		{"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" },
		{"A", "BB", "B", "C", "DB", "D", "EB", "E", "F", "GB", "G", "AB" }
	};

	// Generate combinations of chords.
	for (int i = 0; i < 12; ++i)
	{
		string start = note[0][i];

		combination.clear();
		// Generate Major Chord.
		combination.push_back(note[0][i]);
		
		int nextI = (i + 4) % 12;
		combination.push_back(note[0][nextI]);

		nextI = (nextI + 3) % 12;
		combination.push_back(note[0][nextI]);
		majorChord[getChord(combination)] = start;


		combination.clear();

		// Generate all Minor Chord.
		combination.push_back(note[0][i]); 
		
		nextI = (i + 3) % 12;
		combination.push_back(note[0][nextI]);

		nextI = (nextI + 4) % 12;
		combination.push_back(note[0][nextI]);
		minorChord[getChord(combination)] = start;
	}

	while (cin >> combination[0] >> combination[1] >> combination[2])
	{
		string chord = "";
		
		for (int i = 0; i < 3; ++i)
		{
			chord += combination[i] + (i + 1 == 3?"":" ");
			transform(combination[i].begin(), combination[i].end(), combination[i].begin(), ::toupper);

			if (combination[i].length() == 2 and combination[i][1] == 'B')
			{
				for (int j = 0; j < 12; ++j)
				{
					if (note[1][j] == combination[i])
						combination[i] = note[0][j];
				}
			}
		}

		string currentChord = getChord(combination);

		cout << chord << " is ";

		if (majorChord.count(currentChord) > 0)
			cout << "a " << majorChord[currentChord] << " Major chord.\n";
		else if (minorChord.count(currentChord) > 0) 
			cout << "a " << minorChord[currentChord] << " Minor chord.\n";
		else
			cout << "unrecognized.\n";
	}

	return 0;
}