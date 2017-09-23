/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10812 - Beat the Spread!
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
		long long sum;
		long long difference;
		cin >> sum >> difference;
		
		if(sum < difference or((sum + difference) & 1 or (sum - difference) & 1))
			cout << "impossible\n";
		else
			cout << ((sum + difference) >> 1LL) << " " << ((sum - difference) >> 1LL) << "\n";
	}

	return 0;
}