/*
*	User: Isanchez_Aguilar
*	Problem: UVA 434 - Matty's Blocks
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int i = 0; i < testCases; ++i)
	{
		int k;
		cin >> k;

		vector<int> right(k);
		vector<int> front(k);
	
		for(int j = 0; j < k; ++j)
			cin >> front[j];

		for(int j = 0; j < k; ++j)
			cin >> right[j];

		int minPieces = 0;

		bitset<8> frontNoAvailable;
		bitset<8> rightNoAvailable;
		for(int j = 0; j < k; ++j)
		{
			for(int l = 0; l < k; ++l)
			{
				if(front[j] == right[l] && !frontNoAvailable[j] && !rightNoAvailable[l])
				{
					minPieces += front[j];
					frontNoAvailable[j] = 1;
					rightNoAvailable[l] = 1;
				}
			}
		}

		for(int j = 0; j < k; ++j)
		{
			if(!frontNoAvailable[j])
				minPieces += front[j];
			if(!rightNoAvailable[j])
				minPieces += right[j];
		}
		
		int maxExtraPieces = -minPieces;
		for(int j = 0; j < k; ++j)
		{
			for(int l = 0; l < k; ++l)
				maxExtraPieces += min(front[j], right[l]);
		}

		cout << "Matty needs at least " << minPieces << " blocks, and can add at most " << maxExtraPieces << " extra blocks.\n";
	}

	return 0;
}