/*
*	User: Isanchez_Aguilar
*	Problem: UVA 139 - Telephone Tangles
*/
#include <bits/stdc++.h>

using namespace std;

class Country
{
public:
	double cents;
	string code;
	string name;

	Country()
	{

	}
	Country(string _name, string _code, double _cents)
	{
		name = _name;
		code = _code;
		cents = _cents;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string code;
	istringstream in;
	vector<Country> listCountries;

	while (cin >> code and code != "000000")
	{
		string line;
		cin.ignore(1, ' ');
		getline(cin, line);

		int index = line.find("$");
		string country = line.substr(0, index);
		string price = line.substr(index + 1);

		double p;
		in.clear();
		in.str(price);
		
		in >> p;
		listCountries.push_back(Country(country, code, p / 100.0));
	}

	string telephone;
	while (cin >> telephone and telephone != "#")
	{
		Country c;
		int duration;
		
		cin >> duration;
		bool founded = false;
 		string suscriber = "";

		for (int i = 0; i < listCountries.size(); ++i)
		{	
			code = listCountries[i].code;
			
			if (telephone.find(code) == 0)
			{
				int suscriberLength = telephone.length() - code.length();
				
				bool proposition = (telephone[0] == '0' and telephone[1] == '0' and suscriberLength >= 4 and suscriberLength <= 10);
				proposition = proposition or (telephone[0] == '0' and telephone[1] != '0' and 4 <= suscriberLength and suscriberLength <= 7); 
				
				if (proposition)
				{
					founded = true;
					c = listCountries[i];
					suscriber = telephone.substr(code.length(), suscriberLength);
					break;
				}
			}
		}

		cout.unsetf(ios::right);
		cout << setprecision(2) << fixed;
		cout << setiosflags(ios::left) << setw(16) << telephone;

		if (founded)
		{
			cout << c.name << setiosflags(ios::right) << setw(51 - 16 - c.name.length()) << suscriber;
			cout << setw(5) << duration << setw(6) << c.cents << setw(7) << c.cents * duration << endl;
		}
		else if (telephone[0] != '0')
		{
			cout << "Local" << setiosflags(ios::right) << setw(51 - 16 - 5) << telephone;
			cout << setw(5) << duration << setw(6) << "0.00" << setw(7) << "0.00" << '\n';
		}
		else
		{
			cout << "Unknown" << setiosflags(ios::right) << setw(51 - 16 - 7 + 5) << duration;
			cout << setw(6 + 7) << "-1.00" << '\n';
		}
	}

	return 0;
}