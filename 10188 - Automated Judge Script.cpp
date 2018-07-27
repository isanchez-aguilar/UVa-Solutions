/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10188 - Automated Judge Script
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int t = 0;

	while (cin >> n and n)
	{
		cin.ignore();
		
		string line;
		vs solutionLine;
		string solution = "";
		
		for (int i = 0; i < n; ++i)
		{

			getline(cin, line);

			for (int i = 0; i < line.length(); ++i)
			{
				if (isdigit(line[i]))
					solution.push_back(line[i]);
			}

			string aux = "";
			
			for (int i = 0; i < line.length(); ++i)
			{
				if (not isdigit(line[i]))
					aux.push_back(line[i]);
				else
					aux.push_back(' ');

			}

			solutionLine.push_back(aux);
		}

		cin >> n;
		cin.ignore();
		vs outputLine;
		string output = "";

		for (int i = 0; i < n; ++i)
		{

			getline(cin, line);
			
			for (int i = 0; i < line.length(); ++i)
			{
				if (isdigit(line[i]))
					output.push_back(line[i]);
			}

			string aux = "";
			
			for (int i = 0; i < line.length(); ++i)
			{
				if (not isdigit(line[i]))
					aux.push_back(line[i]);
				else
					aux.push_back(' ');
			}

			outputLine.push_back(aux);
		}

		bool wrongAnswer = false; 
		bool presentationError = outputLine.size() != solutionLine.size();
		
		if (solution.length() != output.length() or solution != output)
			wrongAnswer = true;

		if (not wrongAnswer and not presentationError)
		{
			for (int l = 0; l < solutionLine.size(); ++l)
			{
				if (solutionLine[l].length() != outputLine[l].length() or solutionLine[l] != outputLine[l])
				{
					presentationError = true;
					break;
				}
			}
		}

		cout << "Run #" << ++t << ": ";

		if (wrongAnswer)
			cout << "Wrong Answer\n";
		else if (presentationError)
			cout << "Presentation Error\n";
		else
			cout << "Accepted\n";
	}

	return 0;
}