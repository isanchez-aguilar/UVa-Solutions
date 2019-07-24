/*
*	User: Isanchez_Aguilar
*	Problem: UVA 820 - Internet Bandwidth
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

	inline void addEdge(const int& u, const int& v, int cost)
	{
		if (capacity[u][v] == 0)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		capacity[u][v] += cost;
		capacity[v][u] += cost;
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

		parents[source] = source;
		queue< pair<int, int> > bfs;

		bfs.push(make_pair(source, INF));

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
					parents[v] = u;
					int newFlow = min(flow, capacity[u][v]);
					bfs.push(make_pair(v, newFlow));
				}
			}
		}

		if (maxFlow > 0)
		{
			int currNode = sink;

			// Augmenting path.
			while (currNode != source)
			{
				int prevNode = parents[currNode];
				
				capacity[currNode][prevNode] += maxFlow;
				capacity[prevNode][currNode] -= maxFlow;

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

	int network = 1;
	int nodes, source, sink, edges;
	
	while (cin >> nodes and nodes > 0)
	{
		cin >> source >> sink >> edges;

		--source, --sink;
		Graph model(nodes);

		while (edges--)
		{
			int u, v, cost;
			cin >> u >> v >> cost;

			model.addEdge(--u, --v, cost);
		}

		cout << "Network " << network++ << "\n";
		cout << "The bandwidth is " << model.getMaxFlow(source, sink) << ".\n\n"; 
	}
	
	return 0;
}