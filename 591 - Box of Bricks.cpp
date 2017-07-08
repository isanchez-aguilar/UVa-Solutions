/*
*	User: Isanchez_Aguilar
*	Problem: UVA 591 - Box of Bricks
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int blocks;
	while(cin >> blocks && blocks)
	{
		int boxesNumber = 0;
		vector<int> blocksData(blocks);

		for(int i = 0; i < blocks; ++i)
		{
			cin >> blocksData[i];
			boxesNumber += blocksData[i];
		}
		
		int maxBlocks = boxesNumber / blocks;
		int minMoves = 0;
		
		for(int i = 0; i < blocks; ++i)
		{
			if(maxBlocks < blocksData[i])
				minMoves += blocksData[i] - maxBlocks;
		}
		
		cout << "Set #" << ++t << "\n";
		cout << "The minimum number of moves is " << minMoves << ".\n\n";
	}

	return 0;
}