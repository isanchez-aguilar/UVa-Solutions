/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11566 - Let's Yum Cha!
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int x;
int T;
int K;
int teaCharge;
int maxPayment;
int maxDishes;
int price[101];
int favour[101];
int memo[101][22][1001];

inline double getFavour(int payment, int dishes, int available)
{
	int totalPayment = ceil((double)(payment + teaCharge) * 1.1L);

	if(maxPayment < totalPayment or maxDishes < dishes)
		return INT_MIN;
	
	if(maxPayment == totalPayment or available < 0 or maxDishes == dishes)
		return 0;

	int &c = memo[available][dishes][payment];

	if(c != -1)
		return c;

	return c = max(favour[available] + getFavour(payment + price[available], dishes + 1, available - 1), 
		max((favour[available] << 1) + getFavour(payment + (price[available] << 1), dishes + 2, available - 1), getFavour(payment, dishes, available - 1)));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> N >> x >> T >> K and (N or x or T or K))
	{
		for(int i = 0; i < K; ++i)
		{
			favour[i] = 0;
			cin >> price[i];

			for(int j = 0; j < N + 1; ++j)
			{
				int f;
				cin >> f;
				favour[i] += f;
			}
		}

		memset(memo, -1, sizeof(memo));

		teaCharge = T * (N + 1);
		maxPayment = x * (N + 1);
		maxDishes = (N + 1) << 1;

		cout << fixed << setprecision(2) << getFavour(0, 0, K - 1) / (double)(N + 1) << "\n";
	}

	return 0;
}