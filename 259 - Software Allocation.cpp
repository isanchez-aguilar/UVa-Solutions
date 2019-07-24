/*
*	User: Isanchez_Aguilar
*	Problem: UVA 259 - Software Allocation
*/
#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

class Graph {
public:
	int vertexs;
	vector< vector<int> > adj;
	vector< vector<int> > capacity;

	Graph(){}

	Graph(const int& n):vertexs(n), adj(n), capacity(n, vector<int>(n)){}

	inline void addEdge(int u, int v, int cost)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
		capacity[v][u] = 0;
		capacity[u][v] = cost;
	}

	inline int getMaxFlow(const int& source, const int& sink)
	{
		int flow = 0;
		int newFlow = 0;
		vector<int> parents(vertexs);

		while (newFlow = getMinAugmenting(source, sink, parents))
		{
			flow += newFlow;
			int currNode = sink;

			while (currNode != source)
			{
				int prevNode = parents[currNode];
				capacity[prevNode][currNode] -= newFlow;
				capacity[currNode][prevNode] += newFlow;
				currNode = prevNode;
			}
		}

		return flow;
	}

	inline int getMinAugmenting(const int& source, const int& sink, vector<int>& parents)
	{
		int maxFlow = 0;
		fill(begin(parents), end(parents), -1);

		parents[source] = source;
		queue< pair<int, int> > bfs;

		bfs.push(make_pair(source, INF));

		while (not bfs.empty())
		{
			pair<int, int> data = bfs.front();
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


		return maxFlow;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string data;

	while (getline(cin, data))
	{
		Graph model(38);
		int totalApps = 0;
		const int sink = 37;
		const int source = 0;

		do
		{
			char app = data[0];
			int appId = int(app - 'A' + 1);
			int people = int(data[1] - '0');

			totalApps += people;
			model.addEdge(source, appId, people);

			for (int i = 3; i < int(data.length()) - 1; ++i)
			{
				int computer = int(data[i] - '0');
				model.addEdge(appId, computer + 27, 1);
			}
		} while (getline(cin, data) and data.length() > 0);


		for (int computer = 0; computer < 10; ++computer)
			model.addEdge(computer + 27, sink, 1);

		int amountUsed = model.getMaxFlow(source, sink);

		if (totalApps == amountUsed)
		{
			for (int u = 27; u < 37; ++u)
			{
				bool used = false;

				for (int v = 1; v < 27; ++v)
				{
					if (model.capacity[u][v] == 1)
					{
						used = true;
						cout << char(v - 1 + 'A');
						break;
					}
				}

				if (not used)
					cout << "_";
			}

			cout << "\n";
		}
		else
			cout << "!\n";  
	}


	return 0;
}