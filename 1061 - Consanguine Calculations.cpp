/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1061 - Consanguine Calculations
*/
#include <bits/stdc++.h>

using namespace std;

typedef map<string, string> mss;
typedef pair<string, string> ss;
typedef set<ss> sss;

inline string getBlood(const string& b)
{
	return b.substr(0, b.length() - 1);
}

inline void printParent(const set<string>& parent)
{
	if (parent.size())
	{
		if (parent.size() > 1)
			cout << "{";
		
		for (set<string>::iterator i = parent.begin(); i != parent.end(); ++i)
		{
			if (i != parent.begin())
				cout << ", ";
		
			cout << *i;				
		}

		if (parent.size() > 1)
			cout << "}";

		cout << " ";
	}
	else
		cout << "IMPOSSIBLE ";
	return;
}

inline set<string> getPossibleParents(string blood, sss p, char signP, char signC)
{
	set<string>parent;

	for (sss::iterator i = p.begin(); i != p.end(); ++i)
	{
		const ss& bloods = *i;

		if (bloods.first == blood)
		{
			if (signP == '-' and signC == '+')
				parent.insert(bloods.second + "+");
			else
			{
				parent.insert(bloods.second + "+");
				parent.insert(bloods.second + "-");
			}
		}
		else if (bloods.second == blood)
		{
			if (signP == '-' and signC == '+')
				parent.insert(bloods.first + "+");
			else
			{
				parent.insert(bloods.first + "+");
				parent.insert(bloods.first + "-");
			}
		}
	}

	return parent;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	const string sign[] = {"+", "-"};
	
	mss blood;

	blood["AA"] = "A";
	blood["AB"] = "AB";
	blood["AO"] = "A";
	blood["BB"] = "B";
	blood["BO"] = "B";
	blood["OO"] = "O";

	mss bloodToCombination;

	bloodToCombination["A"] = "AA";
	bloodToCombination["AB"] = "AB";
	bloodToCombination["A"] = "AO";
	bloodToCombination["B"] = "BB";
	bloodToCombination["B"] = "BO";
	bloodToCombination["O"] = "OO";
	
	const string bloodCombination[] = {
		"AA",
		"AB",
		"AO",
		"BB",
		"BO",
		"OO"
	};

	map<string, sss> parents;

	for (int i = 0; i < 6; ++i)
	{
		for (int j = i; j < 6; ++j)
		{
			string blood1 = bloodCombination[i];
			string blood2 = bloodCombination[j];

			for (int k = 0; k < blood1.length(); ++k)
			{
				for (int l = 0; l < blood2.length(); ++l)
				{
					ss combination;
					string currentBlood = "";

					string b1 = blood[blood1];
					string b2 = blood[blood2];

					if (b1 < b2)
						combination = make_pair(b1, b2);
					else
						combination = make_pair(b1, b2);

					if (blood1[k] < blood2[l])
					{
						currentBlood.push_back(blood1[k]);
						currentBlood.push_back(blood2[l]);
					}
					else
					{
						currentBlood.push_back(blood2[l]);
						currentBlood.push_back(blood1[k]);
					}

					parents[blood[currentBlood]].insert(combination);
				}
			}
		}
	}

	int t = 0;
	string bloodType[3];

	while (cin >> bloodType[0] and bloodType[0] != "E")
	{
		cin >> bloodType[1] >> bloodType[2];

		cout << "Case " << ++t << ": ";

		if (bloodType[0] == "?")
		{
			char signP = bloodType[1].back();
			char signC = bloodType[2].back();
			string blood2 = getBlood(bloodType[1]);
			sss p = parents[getBlood(bloodType[2])];

			printParent(getPossibleParents(blood2, p, signP, signC));
			
			cout << bloodType[1] << " " << bloodType[2];
		}
		else if (bloodType[1] == "?")
		{
			char signP = bloodType[0].back();
			char signC = bloodType[2].back();
			string blood1 = getBlood(bloodType[0]);
			sss p = parents[getBlood(bloodType[2])];

			cout << bloodType[0] << " ";

			printParent(getPossibleParents(blood1, p, signP, signC));
			
			cout << bloodType[2];
		}
		else
		{
			set<string> combinations;
			string blood1 = bloodToCombination[getBlood(bloodType[0])];
			string blood2 = bloodToCombination[getBlood(bloodType[1])];
			bool positive = (bloodType[0].back() == '+') or (bloodType[1].back() == '+');

			for (int k = 0; k < blood1.length(); ++k)
			{
				for (int l = 0; l < blood2.length(); ++l)
				{
					string currentBlood = "";

					if (blood1[k] < blood2[l])
					{
						currentBlood.push_back(blood1[k]);
						currentBlood.push_back(blood2[l]);
					}
					else
					{
						currentBlood.push_back(blood2[l]);
						currentBlood.push_back(blood1[k]);
					}

					combinations.insert(blood[currentBlood] + "-");
					
					if (positive)
						combinations.insert(blood[currentBlood] + "+");
				}
			}

			cout << bloodType[0] << " " << bloodType[1] << " ";
			
			if (combinations.size() > 1)
				cout << "{";

			for (set<string>::iterator i = combinations.begin(); i != combinations.end(); ++i)
			{
				if (i != combinations.begin())
					cout << ", ";
			
				cout << *i;
			}
			
			if (combinations.size() > 1)
				cout << "}";
		}

		cout << "\n";
	}

	return 0;
}