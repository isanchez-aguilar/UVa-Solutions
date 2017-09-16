/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11854 - Egypt
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int lenght[3];
	while(cin >> lenght[0] >> lenght[1] >> lenght[2] and (lenght[0] or lenght[1] or lenght[2]))
	{
		int sum = 0;
		sort(lenght, lenght + 3);
		
		if(lenght[0] * lenght[0] + lenght[1] * lenght[1] == lenght[2] * lenght[2])
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}