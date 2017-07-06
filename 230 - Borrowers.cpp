/*
*	User: Isanchez_Aguilar
*	Problem: UVA 230 - Borrowers
*/
#include <bits/stdc++.h>

using namespace std;

// Class to save books' data.
class Book
{
public:
	string title;
	string author;
	Book(string _title, string _author):title(_title), author(_author){}
	inline bool operator<(Book a) { 
		if(this->author == a.author)
			return this->title < a.title;
		return this->author < a.author;
	}
};

typedef vector<Book> vB;
typedef vector<bool> vb;
typedef vector<string> vs;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vB shelf;
	string data;
	map<string, int> books;
	// Read the books.
	while(getline(cin, data) && data[0] != 'E')
	{
		int i = 1;
		string title = "";
		string author = "";
		int length = data.length() - 1;

		for(; data[i] != '\"'; ++i)
			title += data[i];
		
		i += 5;

		for(; i < length; ++i)
			author += data[i];
		shelf.push_back(Book(title, author));
	}
	// Sort books by author.
	int sizeShelf = shelf.size();
	sort(shelf.begin(), shelf.end());
	// Insert sorted books on map with title as key.
	for(int i = 0; i < sizeShelf; ++i)
		books[shelf[i].title] = i;
	// Created book status.
	vb borrowed(sizeShelf);
	vb returned(sizeShelf);
	// Read actions.
	while(getline(cin, data) && data[0] != 'E')
	{
		int i;
		int size;
		string title = "";
		int previousBook = -1;
		int length = data.length() - 1;	
		
		if(data[0] != 'S')
		{
			for(i = 8; i < length; ++i)
				title += data[i];
		}
		
		switch(data[0])
		{
			case 'B':
				borrowed[books[title]] = 1;
				returned[books[title]] = 0;
			break;
			case 'R':
				returned[books[title]] = 1;
			break;
			default:
				for(int i = 0; i < sizeShelf; ++i)
				{
					if(returned[i])
					{
						if(previousBook != -1)
							cout << "Put \"" << shelf[i].title << "\" after \"" << shelf[previousBook].title << "\"\n";
						else
							cout << "Put \"" << shelf[i].title << "\" first\n";
						
						returned[i] = 0;
						borrowed[i] = 0;
						previousBook = i;
					}
					else if(!borrowed[i])
						previousBook = i;
				}
				cout << "END\n";
		}
	}

	return 0;
}