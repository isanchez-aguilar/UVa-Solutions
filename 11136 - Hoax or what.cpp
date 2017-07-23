/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11136 - Hoax or what
*/
#include <bits/stdc++.h>

using namespace std;

typedef multiset<int> msi;
typedef multiset<int>::iterator msii;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int days;
	while(cin >> days && days)
	{
		msi urn;
		long payment = 0;

		while(days--)
		{
			int bills;
			cin >> bills;
			
			while(bills--)
			{
				int total;
				cin >> total;

				urn.insert(total);			
			}
			msii lower = urn.begin();
			msii upper = --urn.end();
			
			payment += *upper - *lower;

			urn.erase(lower);
			urn.erase(upper);
		}
		cout << payment << "\n";
	}

	return 0;
}