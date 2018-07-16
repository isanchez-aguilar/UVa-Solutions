/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10659 - Fitting Text into Slides
*/
#include <bits/stdc++.h>

#define SMALLEST 8
#define LARGEST 28

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int slides;
	cin >> slides;

	for (int s = 0; s < slides; ++s)
	{
		int lines;
		int longestWord = 0;
		
		cin >> lines;
		cin.ignore();

		vector<string> words[lines];

		for (int i = 0; i < lines; ++i)
		{
			string line;
			getline(cin, line);

			string word;
			istringstream in(line);

			while (in >> word)
			{
				words[i].push_back(word);
				longestWord = max(longestWord, (int)word.length());
			}
		}
	
		int width;
		int height;
		int fontSize = 0;
		
		cin >> width >> height;

		int font;
		
		for (fontSize = LARGEST; fontSize >= SMALLEST; --fontSize)
		{
			if(fontSize * lines > height)
				continue;

			int x = 0;
			int y = 0;
			int space;

			for (int i = 0; i < lines; ++i)
			{
				x = 0;
				space = 0;
				y += fontSize;
				
				for (int j = 0; j < words[i].size(); ++j)
				{
					if (x + fontSize * (words[i][j].length() + space) > width)
					{
						y += fontSize;
						x = fontSize * words[i][j].length();
					}

					else
						x += fontSize * (words[i][j].length() + space);
					
					if (x > width or y > height)
					{
						y = height + 1;
						break;
					}

					space = 1;
				}
			}
			
			if (y <= height)
				break;
		}

		if(fontSize >= SMALLEST)
			cout << fontSize << "\n";
		else
			cout << "No solution" << "\n";
	}

	return 0;
}