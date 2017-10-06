/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10943 - How do you add?
*/
#include <bits/stdc++.h>

using namespace std;

int memo[101][101];

int getWays(int sum, int availableNumbers)
{
	if(sum == 0 and availableNumbers == 0)
		return 1;
	
	if(sum < 0 or availableNumbers < 0)
		return 0;

	int &c = memo[sum][availableNumbers];

	if(c != -1)
		return c % 1000000;

	c = 0;
	for(int i = 0; i <= sum; ++i)
		c += getWays(sum - i, availableNumbers - 1) % 1000000;

	return c % 1000000;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int k;
	
	memset(memo, -1, sizeof(memo));
	
	while(cin >> n >> k and (n or k))
		cout << getWays(n, k) << "\n";

	return 0;
}