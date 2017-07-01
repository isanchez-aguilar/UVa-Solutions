/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10469 - To Carry or not to Carry
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i;
	int j;
	
	while (cin >> i >> j)
		cout << (i ^ j) << "\n";
	
	return 0;
}