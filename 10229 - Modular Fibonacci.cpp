/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10229 - Modular Fibonacci
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

inline vector< vector<Long> > multiplyMatrixMod(vector< vector<Long> > a, vector< vector<Long> > b, Long module)
{
	int m = a.size();
	int n = a[0].size();
	int q = b[0].size();
	vector< vector<Long> > ans(m, vector<Long>(q));
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			for (int k = 0; k < n; ++k)
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] % module) % module;
		}
	}

	return ans;
}

inline Long fibonacciMod(Long n, Long m)
{
	if (n == 0 or n == 1)
		return n % m;
	
	--n;
	Long result = 1;
	
	vector< vector<Long> > fiboMatrix(2, vector<Long>(2, 1));
	vector< vector<Long> > recurrencyMatrix(2, vector<Long>(2, 1));
	
	fiboMatrix[1][1] = 0;
	
	while (n > 0)
	{
		if (n & 1)
			recurrencyMatrix = multiplyMatrixMod(recurrencyMatrix, fiboMatrix, m);
		
		n >>= 1;
	
		if (n > 0)
			fiboMatrix = multiplyMatrixMod(fiboMatrix, fiboMatrix, m);
	}
	
	return recurrencyMatrix[0][1];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Long n;
	Long m;
		
	while (cin >> n >> m)
		cout << fibonacciMod(n, 1LL << m) << "\n";

	return 0;
}
