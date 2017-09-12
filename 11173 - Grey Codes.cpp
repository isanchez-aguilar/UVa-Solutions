/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11173 - Grey Codes
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{
		int k;
		int n;
		cin >> n >> k;
	
		cout << (k ^ (k >> 1)) << "\n";
	}

	return 0;
}