/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12532 - Interval Product
*/
#include <bits/stdc++.h>

#define LSOne(S) (S & (-S))

using namespace std;

class FenwickTree
{
public:
	int n;
	vector<int> ft;

	FenwickTree(int _n):n(_n), ft(n, 0) {}
	inline void adjust(int k, int v)
	{
		while(k < n)
		{
			ft[k] += v;
			k += LSOne(k);
		}

		return;
	}
	inline int rsq(int a)
	{
		int sum = 0;

		while(a)
		{
			sum += ft[a];

			a -= LSOne(a);
		}

		return sum;
	}
	inline int rsq(int a, int b) { return rsq(b) - (a == 1?0:rsq(a - 1)); }
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int q;
	while(cin >> n >> q)
	{
		vector<int> data(n + 1);
		FenwickTree ftZeroes(n + 1);
		FenwickTree ftNegatives(n + 1);

		for(int i = 1; i <= n; ++i)
		{
			cin >> data[i];

			if(!data[i])
				ftZeroes.adjust(i, 1);
			else if(data[i] < 0)
				ftNegatives.adjust(i, 1);
		}

		
		for(int i = 0; i < q; ++i)
		{
			int a;
			int b;
			char action;
			
			cin >> action >> a >> b;

			if(action == 'C')
			{
				if((data[a] >= 0 && b < 0) || (data[a] < 0 && b >= 0))
					ftNegatives.adjust(a, 1);

				if(data[a] && !b)
					ftZeroes.adjust(a, 1);
				else if(!data[a] && b)
					ftZeroes.adjust(a, -1);

				data[a] = b;
			}
			else
			{
				if(ftZeroes.rsq(a, b))
					cout << '0';
				else if(ftNegatives.rsq(a, b) & 1)
					cout << '-';
				else
					cout << '+';
			}
		}
		cout << "\n";
	}

	return 0;
}