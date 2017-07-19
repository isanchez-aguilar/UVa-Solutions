/*
*	User: Isanchez_Aguilar
*	Problem: UVA 450 - Little Black Book
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> pss;
typedef multimap<string, string> mss;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	mss listNames;
	int departments;

	cin >> departments;
	
	cin.ignore();
	while(departments--)
	{
		string data;
		string department;

		getline(cin, department);
		while(getline(cin, data) && data.length() != 0)
		{
			int i = 0;
			int commas = 0;
			while(commas != 2)
			{
				if(data[i] == ',')
					++commas;
				++i;
			}

			string lastName;
			while(data[i] != ',')
				lastName += data[i++];
			
			while(data[++i] != ',');

			data.insert(i + 1, department + ",");
			listNames.insert(pss(lastName, data));
		}
	}

	for(mss::iterator i = listNames.begin(); i != listNames.end(); ++i)
	{
		string data = i->second;
		int length = data.length();

		cout << "----------------------------------------\n";
		for(int j = 0, commas = 0; j < length; ++j)
		{
			if(data[j] == ',')
			{
				++commas;
				if(commas < 3)
					cout << " ";
				else
				{
					cout << "\n";
					switch(commas)
					{
						case 4:
							cout << "Department: ";
						break;
						case 5:
							cout << "Home Phone: ";
						break;
						case 6:
							cout << "Work Phone: ";
						break;
						case 7:
							cout << "Campus Box: ";
						break;
					}
				}
			}
			else
				cout << data[j];
		}
		cout << "\n";
	}
	return 0;
}