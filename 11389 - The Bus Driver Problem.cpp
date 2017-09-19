/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11389 - The Bus Driver Problem
*/
#include <bits/stdc++.h>


using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int routes;
	int limit;
	int payment;
	while(cin >> routes >> limit >> payment and (routes or limit or payment))
	{
		vector<int> morning(routes);
		vector<int> evening(routes);

		for(int i = 0; i < routes; ++i)
			cin >> morning[i];

		sort(morning.begin(), morning.end());

		for(int i = 0; i < routes; ++i)
			cin >> evening[i];

		sort(evening.begin(), evening.end(), greater<int>());

		int minPayment = 0;

		for(int i = 0; i < routes; ++i)
		{
			if(limit < morning[i] + evening[i])
				minPayment += (morning[i] + evening[i] - limit) * payment;
		}

		cout << minPayment << "\n";
	}

	return 0;
}
