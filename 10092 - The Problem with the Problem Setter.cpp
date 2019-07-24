/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10092 - The Problem with the Problem Setter
*/
#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

class Graph {
public:
	int nodes;
	vector< vector<int> > adj;
	vector< vector<int> > capacity;

	Graph(){}

	Graph(int n):nodes(n), adj(n), capacity(n, vector<int>(n)){}

	inline void addEdge(const int& u, const int& v, const int& cost)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);

		capacity[u][v] = cost;

		return;
	}

	inline int getMaxFlow(const int& source, const int& sink)
	{
		int flow = 0;
		int newFlow = 0;
		vector<int> parents(nodes);

		while (newFlow = getFlow(source, sink, parents))
			flow += newFlow;

		return flow;
	}

	inline int getFlow(const int& source, const int& sink, vector<int>& parents)
	{
		int maxFlow = 0;
		fill(begin(parents), end(parents), -1);

		queue< pair<int, int> > bfs;
		bfs.push(make_pair(source, INF));
		parents[source] = source;

		while (not bfs.empty())
		{
			const pair<int, int>& data = bfs.front();
			int u = data.first, flow = data.second;
			bfs.pop();

			if (u == sink)
			{
				maxFlow = flow;
				break;
			}

			for (int v : adj[u])
			{
				if (parents[v] == -1 and capacity[u][v] > 0)
				{
					int newFlow = min(flow, capacity[u][v]);
					bfs.push(make_pair(v, newFlow));
					parents[v] = u;
				}
			}
		}

		if (parents[sink] != -1)
		{
			int currNode = sink;
			
			while (currNode != source)
			{
				int prevNode = parents[currNode];

				capacity[prevNode][currNode] -= maxFlow;
				capacity[currNode][prevNode] += maxFlow;

				currNode = prevNode;
			}
		}

		return maxFlow;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int amountCategories, amountProblems;

	while (cin >> amountCategories >> amountProblems and (amountProblems or amountCategories))
	{
		const int source = 0;
		const int sink = amountCategories + amountProblems + 1;

		int totalProblems = 0;
		Graph model(amountCategories + amountProblems + 2);

		for (int i = 0; i < amountCategories; ++i)
		{
			int necessary;
			cin >> necessary;

			totalProblems += necessary;
			model.addEdge(source, i + 1, necessary);
		}

		for (int i = 0; i < amountProblems; ++i)
		{
			int categories;
			cin >> categories;

			const int nodeProblem = i + amountCategories + 1; 

			for (int j = 0; j < categories; ++j)
			{
				int category;
				cin >> category;
				model.addEdge(category, nodeProblem, 1); 
			}

			model.addEdge(nodeProblem, sink, 1);
		}

		int maxProblems = model.getMaxFlow(source, sink);
		cout << short(maxProblems == totalProblems) << "\n";

		if (maxProblems == totalProblems)
		{
			for (int category = 1; category <= amountCategories; ++category)
			{
				bool first = true;
				
				for (int problem = 0; problem < amountProblems; ++ problem)
				{
					const int problemNode = problem + amountCategories + 1;
					
					if (model.capacity[problemNode][category] == 1)
					{
						if (not first)
							cout << " ";

						cout << problem + 1;

						first = false;
					}
				}
			
				cout << "\n";
			}
		}
	}

	return 0;
}