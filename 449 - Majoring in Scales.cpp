/*
*	User: Isanchez_Aguilar
*	Problem: UVA 449 - Majoring in Scales
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

inline int getIntervalMove(string m)
{
	if (m == "SECOND")
		return 1;
	else if (m == "THIRD")
		return 2;
	else if (m == "FOURTH")
		return 3;
	else if (m == "FIFTH")
		return 4;
	else if (m == "SIXTH")
		return 5;
	else if (m == "SEVENTH")
		return 6;

	return 7;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const string major[12][7] = {
		{"C", "D", "E", "F", "G", "A", "B"},
		{"Db", "Eb", "F", "Gb", "Ab", "Bb", "C"},
		{"D", "E", "F#", "G", "A", "B", "C#"},
		{"Eb", "F", "G", "Ab", "Bb", "C", "D"},
		{"E", "F#", "G#", "A", "B", "C#", "D#"},
		{"F", "G", "A", "Bb", "C", "D", "E"},
		{"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F"},
		{"G", "A", "B", "C", "D", "E", "F#"},
		{"Ab", "Bb", "C", "Db", "Eb", "F", "G"},
		{"A", "B", "C#", "D", "E", "F#", "G#"},
		{"Bb", "C", "D", "Eb", "F", "G", "A"},
		{"B", "C#", "D#", "E", "F#", "G#", "A#"}
	};
	const int move[] = {2, 4, 5, 7, 9, 11, 12};
	
	map<string, vs> majorScale;
	// Store all Major scale;
	for (int i = 0; i < 12; ++i)
		majorScale[major[i][0]] = vs(major[i], major[i] + 7);

	string noteMajor;
	while (cin >> noteMajor)
	{
		string line;

		cin.ignore();
		getline(cin, line);
		
		istringstream input(line);
	
		cout << "Key of " << noteMajor << "\n";	
		while (getline(input, line, ';') and line.length())
		{
			string interval;
			string noteStart;
			string direction;
			istringstream in(line);
			
			in >> noteStart >> direction >> interval;

			int index = -1;
			const vs& major = majorScale[noteMajor];

			for (int i = 0; i < major.size(); ++i)
			{
				if (major[i] == noteStart)
				{
					index = i;
					break;
				}
			}

			cout << noteStart << ": ";

			if (index == -1)
				cout << "invalid note for this key\n";
			else
			{
				if (direction[0] == 'D')
				{
					index -= getIntervalMove(interval);
					
					if (index < 0)
						index += 7;
				}
				else
					index = (index + getIntervalMove(interval)) % 7;

				cout << direction << " " << interval << " > " << major[index] << "\n";
			}
		}
		cout << "\n";
	}

	return 0;
}