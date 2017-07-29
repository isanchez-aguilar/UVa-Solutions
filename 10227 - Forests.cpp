/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10227 - Forests
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;

	cin >> testCases;
	vector< bitset<101> > heard(101); 
	while(testCases--)
	{
		int p;
		int t;
		string data;
		cin >> p >> t;
		cin.ignore();

		for(int i = 0; i < p; ++i)
			heard[i].reset();
		
		while(getline(cin, data) && data.length())
		{
			int i;
			int j;
			istringstream in(data);
			
			in >> i >> j;
			heard[i - 1][j - 1] = 1;

		}

		int sameOpinions = 0;
		bitset<101> checked;
		for(int i = 0; i < p; ++i)
		{
			int same = 0;
			if(!checked[i])
			{
				for(int j = i + 1; j < p; ++j)
				{
					if(heard[i] == heard[j])
						checked[j] = 1;
				}
				++sameOpinions;
			}
		}
		cout << sameOpinions << "\n";
		if(testCases)
			cout << "\n";
	}

	return 0;
}