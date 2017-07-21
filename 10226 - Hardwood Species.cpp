/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10226 - Hardwood Species
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	cin.ignore();
	cin.ignore();
	while(testCases--)
	{
		string name;
		int total = 0;
		map<string, int> trees;

		while(getline(cin, name) && name.length())
		{
			++total;
			++trees[name];
		}

		for(map<string, int>::iterator i = trees.begin(); i != trees.end(); ++i)
			cout << i->first << " " << fixed << setprecision(4) << 100.0 * ((double)i->second / total) << "\n";

		if(testCases)
			cout << "\n";
	}

	return 0;
}