/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1230 - MODEX
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x;
ll n;

ll modExp(ll y)
{
	if(!y)
		return 1;

	if(y & 1)
	{
		ll ans = modExp(y - 1) % n;
		return (x * ans) % n;
	}
	
	ll ans = modExp(y >> 1LL) % n;
	return (ans * ans ) % n;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	
	while(cin >> t && t)
	{
		ll y;
		while(t--)
		{
			cin >> x >> y >> n;
			cout << modExp(y) << "\n";
		}
	}

	return 0;
}