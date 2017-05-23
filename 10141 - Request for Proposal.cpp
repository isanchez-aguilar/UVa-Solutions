/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10141 - Request for Proposal
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variables to save the data of test case.
	string word;
	int proposals;
	int requirements;
	int testCase = 0;
	// Read while not EOF and requirements and proposals are not equal to zero.
	while(cin >> requirements >> proposals && (requirements || proposals))
	{
		// Variables to save the data of proposal.
		double price;
		int maximumRequirements = -1;
		string maximumName;
		// Read the name of requirements.
		for(int i = 0; i < requirements; i++)
		{
			// Ignore the character '\n'.
			cin.ignore();
			getline(cin, word);
		}
		// Read all proposals.
		while(proposals--)
		{
			// Variables to save the data of current proposal.
			string requirement;
			double currentPrice;
			int currentRequirements;
			// Read the name of proposal and it data.
			getline(cin,requirement);
			cin >> currentPrice >> currentRequirements;
			cin.ignore();
			// If It proposal has more requirements than the maximum the It is the new maximum.
			if(currentRequirements > maximumRequirements)
			{
				price = currentPrice;
				maximumName = requirement;
				maximumRequirements = currentRequirements;
			}
			// If It proposal has same requirements but is cheaper then is the new maximum. 
			else if(currentRequirements == maximumRequirements && currentPrice < price)
			{
				price = currentPrice;
				maximumName = requirement;
				maximumRequirements = currentRequirements;
			}
			// Read the name of requirements.
			for(int i = 0; i < currentRequirements; i++)
				getline(cin, word);
		}
		// If It is not the first test case the print a '\n'.
		if(++testCase > 1)
			cout << '\n';
		// Print the name of most compliant proposal.
		cout << "RFP #" << testCase << '\n' << maximumName << '\n';
	}
	return 0;
}