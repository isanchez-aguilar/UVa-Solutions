/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12136 - Schedule of a Married Man
*/
#include <bits/stdc++.h>

using namespace std;

inline int getMinutes()
{
		int h;
		int m;
		char dot;
		
		cin >> h >> dot >> m;

		return h * 60 + m;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int t = 1; t <= n; ++t)
	{
		cout << "Case " << t << ": ";
	
		int a1 = getMinutes();
		int b1 = getMinutes();
		int a2 = getMinutes();
		int b2 = getMinutes();
		//cout << a1 << " " << b1 << "," << a2 << "," << b2 << "==" << (a1 >= a2 and a2 <= b1) << endl;
		if((a1 <= a2 and a2 <= b1) or (a1 <= b2 and b2 <= b1) or (a2 <= a1 and (b1 <= b2 or a1 <= b2)))
			cout << "Mrs Meeting\n";
		else
			cout << "Hits Meeting\n";

	}

	return 0;
}