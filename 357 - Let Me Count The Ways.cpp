/*
*	User: Isanchez_Aguilar
*	Problem: UVA 357 - Let Me Count The Ways
*/
#include <bits/stdc++.h>

#define MAX 30001

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<long long> ways(MAX, 1);
	const int values[4] = {5, 10, 25, 50};

	for(int i = 0; i < 4; ++i)
	{
		for(int j = values[i]; j < MAX; ++j)
			ways[j] += ways[j - values[i]]; 
	}

	int n;
	while(cin >> n)
	{
		if(ways[n] == 1)
			cout << "There is only 1 way to produce " << n << " cents change.\n";
		else
			cout << "There are " << ways[n] << " ways to produce " << n << " cents change.\n";
	}

	return 0;
}