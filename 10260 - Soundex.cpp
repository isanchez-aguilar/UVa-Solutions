/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10260 - Soundex
*/
#include <bits/stdc++.h>

using namespace std; 

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string word;
	const int values[] = {-1, 1, 2, 3, -1, 1, 2, -1, -1, 2, 2, 4, 5, 5, -1, 1, 2, 6, 2, 3, -1, 1, -1, 2, -1, 2};

	while(cin >> word)
	{
		int previous = -1;
		int length = word.length();
		
		for(int i = 0; i < length; ++i)
		{
			int value = values[word[i] - 'A'];
			
			if(previous != value && value != -1)
				cout << value;
			
			previous = value;
		}
		cout << "\n";
	}

	return 0;
}