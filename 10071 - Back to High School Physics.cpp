/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10071 - Back to High School Physics
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Data of particle.
	int speed;
	int time;
	// Read while not EOF.
	while(cin >> speed >> time)
		cout << speed * time * 2 << "\n";	
	return 0;
}