/*
*	User: Isanchez_Aguilar
*	Problem: UVA 230 - Borrowers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string line;
	map<string, int> books;
	vector< pair<string, string> > shelf;
	
	// Read the books.
	while (getline(cin, line) and line[0] != 'E')
	{
		string title;
		string author;

		istringstream in(line);

		in.ignore(1, '"');
		getline(in, title, '"');
		
		// Ignore first space.
		in.ignore(1, ' ');
		// Ignore 'by' with second space.
		in.ignore(2, ' ');

		getline(in, author, '"');
		shelf.push_back(make_pair(author, title));
	}

	// Sort books by author.
	int shelfSize = shelf.size();
	sort(shelf.begin(), shelf.end());
	
	// Insert sorted books on map with title as key.
	for (int i = 0; i < shelfSize; ++i)
		books[shelf[i].second] = i;
	
	// Created book status.
	vector<bool> borrowed(shelfSize);
	vector<bool> returned(shelfSize);
	
	// Read actions.
	while (getline(cin, line) and line[0] != 'E')
	{
		string title;
		int previousBook = -1;
		
		istringstream in(line);

		if (line[0] != 'S')
		{
			in.ignore(8, '\"');
			getline(in, title, '\"');
		}
		
		switch (line[0])
		{
			case 'B':
				borrowed[books[title]] = true;
				returned[books[title]] = false;
			break;

			case 'R':
				returned[books[title]] = true;
			break;
			
			default:
				for (int i = 0; i < shelfSize; ++i)
				{
					if (returned[i])
					{
						if (previousBook != -1)
							cout << "Put \"" << shelf[i].second << "\" after \"" << shelf[previousBook].second << "\"\n";
						else
							cout << "Put \"" << shelf[i].second << "\" first\n";
						
						returned[i] = false;
						borrowed[i] = false;
						
						previousBook = i;
					}
					else if (not borrowed[i])					
						previousBook = i;
				}

				cout << "END\n";
		}
	}

	return 0;
}