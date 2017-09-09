/*
*	User: Isanchez_Aguilar
*	Problem: UVA 193 - Graph Coloring
*/
#include <bits/stdc++.h>

#define WHITE 0
#define BLACK 1
#define MAX 105

using namespace std;

int n;
int colour[MAX];
int blackSolution;
vector<int> solution;
bitset<MAX> visited;
vector<int> adj[MAX];

void findSolution(int v)
{
	if(n < v)
	{
		int blackNodes = count(colour + 1, colour + n + 1, BLACK);
		if(blackSolution < blackNodes)
		{
			blackSolution = blackNodes;
			solution.clear();

			for(int i = 1, j = 0; i <= n; ++i)
			{
				if(colour[i] == BLACK)
					solution.push_back(i);
			}
		}
		return;
	}

	int size = adj[v].size();
	bool blackNeighbor = false;

	for(int i = 0; i < size; ++i)
	{
		int j = adj[v][i];
		if(visited[j] and colour[j] == BLACK)
		{
			blackNeighbor = true;
			break;
		}
	}

	visited[v] = true;

	if(not blackNeighbor)
	{
		colour[v] = BLACK;
		findSolution(v + 1);
	}
	colour[v] = WHITE;
	findSolution(v + 1);
	visited[v] = false;
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i)
			adj[i].clear();

		for(int i = 0; i < k; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			
		}

		blackSolution = -1;
		for(int i = 1; i <= n; ++i)
		{
			if(not visited[i])
				findSolution(i);
		}
		
		cout << blackSolution << "\n";
		if(blackSolution)
			cout << solution[0];
		for(int i = 1; i < blackSolution; ++i)
			cout << " " << solution[i];
		cout << "\n";
	}

	return 0;
}