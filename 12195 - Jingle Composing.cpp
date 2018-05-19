/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12195 - Jingle Composing
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string line;
	while (cin >> line and line != "*")
	{
		int total = 0;
		int measure = 0;
		
		for (int i = 1; i < line.length(); ++i)
		{
			if (line[i] == '/')
			{
				if (measure == 64)
					++total;
					
				measure = 0;
				
				continue;
			}
			
			switch (line[i])
			{
				case 'W':
					measure += 64;
					break;
				case 'H':
					measure += 32;
					break;
				case 'Q':
					measure += 16;
					break;
				case 'E':
					measure += 8;
					break;
				case 'S':
					measure += 4;
					break;
				case 'T':
					measure += 2;
					break;
				default:
					measure += 1;
					break;
			}
		}
		
		cout << total << "\n";
	}
	
	return 0;
}
