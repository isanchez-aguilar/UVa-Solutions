/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10721 - Bar Codes
*/
#include <bits/stdc++.h>

using namespace std;

int m;
long long memo[51][51];

inline long long getNumberSymbols(int n, int k)
{

	long long &c = memo[n][k];
	
	if(c != -1)
		return c;
	
	if(not(n or k))
		return c = 1;
	
	if(n == 0)
		return n;
	
	if(k == 0)
		return k;

	c = 0;
	for(int i = 1; i <= n and i <= m; ++i)
		c += getNumberSymbols(n - i, k - 1);

	return c;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int k;

	while(cin >> n >> k >> m)
	{
		memset(memo, -1, sizeof(memo));
		cout << getNumberSymbols(n, k) << "\n";
	}

	return 0;
}