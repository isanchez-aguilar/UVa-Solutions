/*
*	User: Isanchez_Aguilar
*	Problem: UVA 
*/
#include <bits/stdc++.h>

using namespace std;

class Mx
{
public:
	int priority;
	string to;
	string from;

	Mx(){}
	Mx(string _to, string _from, int _priority)
	{
		to = _to;
		from = _from;
		priority = _priority;
	}

	inline bool operator<(const Mx a)
	{
		return priority < a.priority;
	}
};

inline int parseInt(string n)
{
	int number;
	istringstream in(n);

	in >> number;

	return number;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string previousAddres = "";

	cin >> n;
	cin.ignore(1, '\n');
	
	vector<Mx> MxRecord;	
	map<string, bool> available;

	for (int i = 0; i < n; ++i)
	{
		string line;
		getline(cin, line);

		vector<string> input;
		istringstream in(line);

		while (in >> line)
			input.push_back(line);

		string to;
		string from;
		int priority;

		if (input.size() == 3)
		{
 			to = input[2];
			from = input[0];
 			priority = parseInt(input[1]);
		}

		else
		{
 			to = input[1];
 			priority = parseInt(input[0]);
			from = previousAddres;
		}

		available[to] = true;
		previousAddres = from;
		MxRecord.push_back(Mx(to, from, priority));
	}

	// Sorted by priority.
	sort(MxRecord.begin(), MxRecord.end());

	char option;
	string address;
	
	while (cin >> option and option != 'X')
	{
		cin >> address;
		
		if (option == 'A')
		{
			cout << address << " =>";

			for (int i = 0; i < MxRecord.size(); ++i)
			{
				bool invalid = false;
				const Mx& current = MxRecord[i];
				
				if (address == current.from)
					invalid = not available[current.to];

				else if (current.from[0] == '*' and available[current.to])
				{
					const string from = current.from;

					int j = from.length() - 1;
					int k = address.length() - 1;

					while (from[j] != '*')
					{
						if (from[j--] != address[k--])
						{
							invalid = true;
							break;
						}
					}

				}
				else
					invalid = true;
				
				if (not invalid)
				{
					cout << " " << current.to;
					break;
				}
			}

			cout << "\n";
		}
		else
			available[address] = option == 'U';
	}

	return 0;
}