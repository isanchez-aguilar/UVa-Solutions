/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12015 - Google is Feeling Luckys
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Variable to save the number of test cases.
	int testCases;
	// Read the number of test cases.
	cin >> testCases;
	// 
	for(int i = 1; i <= testCases; ++i)
	{
		// Initialize the max to zero.
		int maxRelevance = 0;
		// Array to save the urls with index equal to relevance.
		vector< vector<string> > urls(100);
		for(int j = 0; j < 10; ++j)
		{
			// Variable to save the data of page. 
			string url;
			int relevance;
			// Read data of page.
			cin >> url >> relevance;
			// Get maximum value between the current revelance and the maxRelevance.
			maxRelevance = max(relevance - 1, maxRelevance);
			// Add url to array with index relevance - 1.
			urls[relevance - 1].push_back(url);
		}
		// Print information of number test case.
		cout << "Case #" << i << ":\n";
		// Print all pages with relevance maxRelevance.
		for(int j = 0; j < urls[maxRelevance].size(); ++j)
			cout << urls[maxRelevance][j] << "\n";
	}
	return 0;
}