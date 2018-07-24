/*
*	User: Isanchez_Aguilar
*	Problem: UVA 405 - Message Routing
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

class Mta
{
public:
	vs address;
	string name;
	string country;

	Mta(){}
	Mta(string _name, string _country, vs _address)
	{
		name = _name;
		country = _country;
		address = _address;
	}
};

typedef vector<Mta> vMta;

inline bool isSameAddress(const vs& a, const vs& b)
{
	for (int i = 0; i < 3; ++i)
	{
		if (a[i] != "*" and b[i] != "*" and a[i] != b[i])
			return false;
	}

	return true;
}

inline bool isSameCountry(const string& a, const string& b)
{
	return a == "*" or b == "*" or a == b;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int t = 0;
	bool visited[10];

	while (cin >> n)
	{
		map<string, int> indexName;
		map<int, string> nameIndex;
		map<string, vMta > routingTable;
		
		for (int i = 0; i < n; ++i)
		{
			int adj;
			string name;
			cin >> name >> adj;
			
			indexName[name] = i;

			for (int j = 0; j < adj; ++j)
			{
				string mta;
				vs address(3);
				string country;
				
				cin >> mta >> country;
				
				for (int k = 0; k < 3; ++k)
					cin >> address[k];
					
				routingTable[name].push_back(Mta(mta, country, address));
			}
		}
		
		int m;
		cin >> m;

		cout << "Scenario # " << ++t << "\n";
		
		for (int i = 1; i <= m; ++i)
		{
			string mta;
			string country;
			vs address(3);
			
			cin >> mta >> country;
						
			for (int j = 0; j < 3; ++j)
				cin >> address[j];
			
			bool cycle = false;
			int lengthPath = 0;
			string currentMta = mta;
			int currentIndex = indexName[mta];
			memset(visited, false, sizeof visited);

			while (not visited[currentIndex])
			{
				++lengthPath;
				bool found = false;
				visited[currentIndex] = true;
				const vMta& current = routingTable[currentMta];
				
				for (int j = 0; j < current.size(); ++j)
				{
					const vs& a = current[j].address;
					
					if (isSameCountry(country, current[j].country) and isSameAddress(a, address))
					{
						found = true;
						currentIndex = indexName[current[j].name];
						
						if (visited[currentIndex] and currentMta != current[j].name)
							cycle = true;
						
						currentMta = current[j].name;
	
						break;
					}
				}
	
				if (not found)
				{

					currentIndex = -1;
					break;
				}
			}
			
			cout << i;

			if (currentIndex == -1)
				cout << " -- unable to route at " << currentMta << "\n";
			else
			{
				if (cycle)
					cout << " -- circular routing detected by " << currentMta << "\n";
				else
					cout << " -- delivered to " << currentMta << "\n";
			}	
		}

		cout << "\n";
	}
	
	return 0;
}