/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11286 - Conformity
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int frosh;
	vector<string> id(5);
	
	while(cin >> frosh && frosh)
	{
		int mostPopular = -1;
		map<string, int> combinations;
		
		while(frosh--)
		{
			string key("");

			for(int i = 0; i < 5;  ++i)
				cin >> id[i];
			
			sort(id.begin(), id.end());

			for(int i = 0; i < 5;  ++i)
				key += id[i];

			if(combinations.count(key))
				mostPopular = max(mostPopular, ++combinations[key]);
			else
			{
				combinations[key] = 1;
				mostPopular = max(mostPopular, combinations[key]);
			}

		}

		int coincidences = 0;
		for(map<string, int>::iterator i = combinations.begin(); i != combinations.end(); ++i)
		{
			if(mostPopular == i->second)
				coincidences += mostPopular;
		}

		cout << coincidences << "\n";

	}

	return 0;
}