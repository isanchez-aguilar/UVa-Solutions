/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12455 - Bars
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int length;
int bars[21];

bool isPossible(int start, int sum)
{
	if(sum == length)
		return true;
	if(n <= start or sum > length)
		return false;

	bool possible = false;
	
	for(int i = start; i < n and !possible; ++i)
		possible = isPossible(i + 1, bars[i] + sum);

	return possible;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while(testCases--)
	{	
		cin >> length >> n;

		for(int i = 0; i < n; ++i)
			cin >> bars[i];

		if(isPossible(0, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}