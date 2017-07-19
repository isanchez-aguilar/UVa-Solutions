/*
*	User: Isanchez_Aguilar
*	Problem: UVA 855 - Lunch in Grid City
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
		int friends;
		int streets;
		int avenues;

		cin >> streets >> avenues >> friends;
		
		vector<int> streetPoints(friends);
		vector<int> avenuePoints(friends);

		for(int i = 0; i < friends; ++i)
			cin >> streetPoints[i] >> avenuePoints[i];
		
		sort(streetPoints.begin(), streetPoints.end());
		sort(avenuePoints.begin(), avenuePoints.end());

		int i = (friends >> 1) - 1;

		if(friends & 1)
			++i;

		cout << "(Street: " << streetPoints[i] << ", Avenue: " << avenuePoints[i] << ")\n"; 
	}

	return 0;
}