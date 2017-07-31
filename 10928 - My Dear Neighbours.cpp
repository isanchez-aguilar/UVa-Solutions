/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10928 - My Dear Neighbours
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;
	while(testCases--)
	{
		int p;
		cin >> p;
		cin.ignore();

		int minNeighbors = p;
		vector<int> neighbors(p);
		
		for(int i = 0; i < p; ++i)
		{
			string adj;
			getline(cin, adj);
			istringstream in(adj);
			
			int j;
			neighbors[i] = 0;
			
			while(in >> j && ++neighbors[i]);

			minNeighbors = min(minNeighbors, neighbors[i]);
		}

		int j = 0;
		for(int i = 0; i < p; ++i)
		{

			if(minNeighbors == neighbors[i])
			{
				if(j++)
					cout << " ";
				cout << i + 1; 
			}
		}
		cout << "\n";
	}

	return 0;
}