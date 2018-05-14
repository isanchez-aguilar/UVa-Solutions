/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10528 - Major Scales
*/
#include <bits/stdc++.h>

using namespace std;

const string note[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

inline int getValue(string n)
{
	for (int i = 0; i < 12; ++i)
	{
		if (n == note[i])
			return i;
	}
	
	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string line;
	bool available[12];
	const bool major[12] = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1};
	
	while (getline(cin, line) and line != "END")
	{
		vector<string> notes;
		istringstream in(line);
		memset(available, false, sizeof available);
		
		while (in >> line)
		{
			notes.push_back(line);
			available[getValue(line)] = true;
		}	
		int n = 0;
		for (int i = 0; i < 12; ++i)
		{
			bool isMajor = false;
			for (int j = 0; j < 12; ++j)
			{
				if (available[(i + j) % 12])
				{
					if (major[j])
						isMajor = true;
					else
					{
						isMajor = false;
						break;
					}
				}
			}
			
			if (isMajor)
			{
				if (n++)
					cout << " ";
				cout << note[i];
			}
		}
		
		cout << "\n";
	}
	
	return 0;
}
