/*
*	User: Isanchez_Aguilar
*	Problem: UVA 630 - Anagrams (II)
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;
typedef map<string, vs> msvs;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string input;
	int testCases;
	msvs dictionary;
	
	cin >> testCases;
	while (testCases--)
	{
		int n;
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> input;
			string aux = input;
			
			sort(input.begin(), input.end());
			dictionary[input].push_back(aux);
		}
		
		while (cin >> input and input != "END")
		{
			string aux = input;
			cout << "Anagrams for: " << aux << "\n";
			sort(aux.begin(), aux.end());

			if (dictionary.count(aux) > 0)
			{
				int j = 0;
				for (vs::iterator i = dictionary[aux].begin(); i != dictionary[aux].end(); ++i)
					cout << setw(3) << ++j << ") " << *i << "\n";
			}
			else
				cout << "No anagrams for: " << input << "\n";
		}
		
		if (testCases)
		{
			cout << '\n';
			dictionary.clear();
		}
	}
	
	return 0;
}
