/*
*	User: Isanchez_Aguilar
*	Problem: UVA 101 - The Blocks Problem
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int numberBlocks;
	cin >> numberBlocks;

	vvi blocks(numberBlocks, vi(1));
	vpii blocksPosition(numberBlocks);

	for(int i = 0; i < numberBlocks; ++i)
	{
		blocks[i][0] = i;
		blocksPosition[i].first = i;
		blocksPosition[i].second = 0;
	} 

	string instruction;
	while(cin >> instruction && instruction[0] != 'q')
	{
		int a;
		int b;
		string way;
		cin >> a >> way >> b;
		if(a != b && blocksPosition[a].first != blocksPosition[b].first)
		{
			list<int> backInitialPosition;
			int iA = blocksPosition[a].first;
			int iB = blocksPosition[b].first;
			int jA = blocksPosition[a].second;
			int jB = blocksPosition[b].second;

			if(instruction[0] == 'm')
			{
				int size = blocks[iA].size();

				while(jA < --size)
				{
					backInitialPosition.push_back(blocks[iA][size]);
					blocks[iA].pop_back();
				}
				blocks[iA].pop_back();

				if(way[1] == 'v')
					blocksPosition[a].second = blocks[iB].size();
				else
				{

					size = blocks[iB].size();

					while(jB < --size)
					{
						backInitialPosition.push_back(blocks[iB][size]);
						blocks[iB].pop_back();
					}

					blocksPosition[a].second = jB + 1;

				}
				while(!backInitialPosition.empty())
				{
					int currentBlock = backInitialPosition.front();
	
					backInitialPosition.pop_front();
					int size = blocks[currentBlock].size();
					while(size--)
					{
						backInitialPosition.push_back(blocks[currentBlock][size]);
						blocks[currentBlock].pop_back();
					}
					blocks[currentBlock].push_back(currentBlock);
					blocksPosition[currentBlock].first = currentBlock;
					blocksPosition[currentBlock].second = 0;
				}

				blocks[iB].push_back(a);
				blocksPosition[a].first = iB;
				
			}
			else
			{
				int size = blocks[iB].size();
				if(way[1] != 'v')
				{

					while(jB < --size)
					{
						backInitialPosition.push_back(blocks[iB][size]);
						blocks[iB].pop_back();
					}
					
					while(!backInitialPosition.empty())
					{
						int currentBlock = backInitialPosition.front();
		
						backInitialPosition.pop_front();
						int size = blocks[currentBlock].size();
						while(size--)
						{
							backInitialPosition.push_back(blocks[currentBlock][size]);
							blocks[currentBlock].pop_back();
						}
						blocks[currentBlock].push_back(currentBlock);
						blocksPosition[currentBlock].first = currentBlock;
						blocksPosition[currentBlock].second = 0;
					}

				}
				size = blocks[iB].size();
				blocks[iB].insert(blocks[iB].end(), blocks[iA].begin() + jA, blocks[iA].end());
				for(int j = size; j < blocks[iB].size(); ++j)
				{
					blocksPosition[blocks[iB][j]].first = iB;
					blocksPosition[blocks[iB][j]].second = j;
				}
				blocks[iA].erase(blocks[iA].begin() + jA, blocks[iA].end());
			}
		}
	}

	for(int i = 0; i < numberBlocks; ++i)
	{
		cout << i << ":";

		int size = blocks[i].size();
		for(int j = 0; j < size; ++j)
		{
			cout << " " << blocks[i][j];
		}
		cout << "\n";
	}
	return 0;
}