/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11221 - Magic square palindromes.
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	char matrix[100][100];
	
	cin.ignore();

	for (int t = 1; t <= testCases; ++t)
	{
		string s;
		string aux;
		getline(cin, aux);
		
		for (int i = 0; i < aux.length(); ++i)
		{
			if (isalpha(aux[i]))
				s += aux[i]; 
		}
		
		int sqRoot = sqrt(s.length());

		bool isMagic = true;
		if (sqRoot * sqRoot != s.length())
			isMagic = false;
		else 
		{
			for (int i = 0; i < sqRoot; ++i)
			{
				for (int j = 0; j < sqRoot; ++j)
					matrix[i][j] = s[i * sqRoot + j];
			}

			for (int j = 0, k = 0; j < sqRoot and isMagic; ++j)
			{
				for (int i = 0; i < sqRoot; ++i, ++k)
				{
					if (s[k] != matrix[i][j] or s[k] != matrix[sqRoot - i - 1][sqRoot - j - 1] or s[k] != matrix[sqRoot - j - 1][sqRoot - i - 1])
					{
						isMagic = false;
						break;
					}
				}
			}
		}
		cout << "Case #" << t << ":\n";
		if (isMagic)
			cout << sqRoot << "\n";
		else
			cout << "No magic :(\n";
	}

	return 0;
}