/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10511 - Councilling
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

	int testCases;
	cin >> testCases;
	
	cin.ignore();
	cin.ignore();

	string data, name, party, club;

	while(testCases--)
	{
		map<string, int> idClubs;
		map<string, int> idParties;
		map<string, int> idPeople;

		map<int, string> nameClubs;
		map<int, string> namePeople;
		map<int, string> nameParties;

		vector< pair<int, int> > adjClubPerson;
		vector< pair<int, int> > adjPersonParty;

		while(getline(cin, data) and int(data.length()) > 0)
		{
			cerr << data << endl;
			istringstream in(data);

			in >> name >> party;

			const int idPerson = idPeople.size();
				
			idPeople[name] = idPerson;
			namePeople[idPerson] = name;

			if (idParties.count(party) == 0)
			{
				const int id = idParties.size();
				
				idParties[party] = id;
				nameParties[id] = party;
			}

			const int idParty = idParties[party];

			adjPersonParty.push_back(make_pair(idPerson, idParty));

			while (in >> club)
			{
				if (idClubs.count(club) == 0)
				{
					const int id = idClubs.size();

					idClubs[club] = id;
					nameClubs[id] = club;
				}

				const int idClub = idClubs[club];
				adjClubPerson.push_back(make_pair(idClub, idPerson));
			}
		}

		const int source = 0;
		const int sink = idClubs.size() + idPeople.size() + idParties.size() + 1;

		Graph model(sink + 1);

		for (int i = 0; i < idClubs.size(); ++i)
			model.addEdge(source, i + 1, 1);

		for (const pair<int, int>& clubPerson : adjClubPerson)
		{
			const int nodeClub = clubPerson.first + 1;
			const int nodePerson = clubPerson.second + idClubs.size() + 1;

			model.addEdge(nodeClub, nodePerson, 1);
		}

		for (const pair<int, int>& personParty: adjPersonParty)
		{
			const int nodePerson = personParty.first + idClubs.size() + 1;
			const int nodeParty = personParty.second + idClubs.size() + idPeople.size() + 1;

			model.addEdge(nodePerson, nodeParty, 1);
		}

		for (int i = 0; i < idParties.size(); ++i)
		{
			const int nodeParty = i + idClubs.size() + idPeople.size() + 1;
			model.addEdge(nodeParty, sink, (idClubs.size() - 1) / 2);
		}

		int maxMembers = model.getMaxFlow(source, sink);

		if (maxMembers == idClubs.size())
		{
			for (int idPerson = 0; idPerson < idPeople.size(); ++idPerson)
			{
				const int nodePerson = idPerson + idClubs.size() + 1;
				
				for (int idClub = 0; idClub < idClubs.size(); ++idClub)
				{
					const int nodeClub = idClub + 1;

					if (model.capacity[nodePerson][nodeClub] == 1)
					{
						club = nameClubs[idClub];
						name = namePeople[idPerson];

						cout << name << " " << club << "\n";

						break;
					}
				}
			}
		}
		else
			cout << "Impossible.\n";

		if (testCases)
			cout << "\n";
	}

	return 0;
}