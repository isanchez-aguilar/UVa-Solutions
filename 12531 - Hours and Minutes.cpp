/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12531 - Hours and Minutes
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int angle;
	while (cin >> angle)
		cout << (angle % 6 == 0?"Y\n":"N\n");

	return 0;
}