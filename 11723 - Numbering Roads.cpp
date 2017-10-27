/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11723 - Numbering Roads
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int r;
	int n;
	int t = 0;
	
	while(cin >> r >> n and (r or n))
	{
		int d = ceil((double)(r - n) / n);
		if(d <= 26)
			cout << "Case " << ++t << ": " << d << "\n";
		else
			cout << "Case " << ++t << ": impossible\n";
	}
	
	return 0;
}
