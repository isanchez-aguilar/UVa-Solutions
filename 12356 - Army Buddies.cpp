/*
*	User: Isanchez_Aguilar
*	Problem: UVA 112356 - Army Buddies
*/
#include <bits/stdc++.h>

#define MAX 100003

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int L[MAX];
	int R[MAX];
	int reports;
	int soldiers;
	while(cin >> soldiers >> reports && soldiers)
	{
		for(int i = 1; i <= soldiers; ++i)
		{
			L[i] = i - 1;
			R[i] = i + 1;
		}

		L[1] = -1;
		R[soldiers] = -1;
		
		for(int i = 0; i < reports; ++i)
		{
			int l;
			int r;
			cin >> l >> r;

			L[R[r]] = L[l];
			R[L[l]] = R[r];

			if(L[l] == -1)
				cout << "* ";
			else
				cout << L[l] << " ";

			if(R[r] == -1)
				cout << "*\n";
			else
				cout << R[r] << "\n";
		}
		cout << "-\n";
	}

	return 0;
}