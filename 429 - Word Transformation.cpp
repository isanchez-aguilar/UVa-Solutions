/*
*	User: Isanchez_Aguilar
*	Problem: UVA 429 - Word Transformation
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> words;

inline bool oneDifference(int i, int j)
{
	string p = words[i];
	string q = words[j];
	int differences = 0;

	if(p.length() == q.length())
	{
		for(int i = 0; i < p.length(); ++i)
		{
			if(p[i] != q[i])
			{
				if(++differences > 1)
					return false;
			}
		}

		return true;
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		string s;
		words.clear();
		
		while(cin >> s and s != "*")
			words.push_back(s);
		
		int size = words.size();

		vector<int> adj[size];
		for(int i = 0; i < size; ++i)
		{
			for(int j = i + 1; j < size; ++j)
			{
				if(i != j and oneDifference(i, j))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		cin.ignore();

		while(getline(cin, s) and s.length())
		{
			string a;
			string b;
			stringstream in(s);
			
			in >> a >> b;
			int moves = -1;
			queue<int> node;
			vector<int> move(size, INT_MAX);
			int start = distance(words.begin(), find(words.begin(), words.end(), a));

			move[start] = 0;
			node.push(start);

			while(not node.empty())
			{
				int u = node.front();
					
				node.pop();
				int size = adj[u].size();
				for(int i = 0; i < size; ++i)
				{
					int v = adj[u][i];
					if(move[v] == INT_MAX)
					{
						move[v] = move[u] + 1;
						if(words[v] == b)
						{
							moves = move[v];
							break;
						}

						node.push(v);
					}	
				}

				if(moves != -1)
					break;
			}

			cout << s << " " << moves << "\n";
		}

		if(testCases)
			cout << "\n";
	}

	return 0;
}
