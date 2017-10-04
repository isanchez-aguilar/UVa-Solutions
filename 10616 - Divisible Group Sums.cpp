/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10616 - Divisible Group Sums
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int d;
int numbers[201];
int memo[201][11][22];

int searchArrays(int i, int currentSize, int currentSum)
{
	if(currentSize == m)
	{
		if(!currentSum)
			return 1;
		return 0;
	}

	if(n <= i)
		return 0;

	int &c = memo[i][currentSize][currentSum];

	if(c != -1)
		return c;

	int withNext = 0;
	int withoutNext = 0;

	int sum = currentSum + numbers[i];
	sum %= d;

	if(sum < 0)
		sum += d;

	withNext = searchArrays(i + 1, currentSize + 1, sum);
	withoutNext = searchArrays(i + 1, currentSize, currentSum % d);

	return c = withNext + withoutNext;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int set = 1;
	int queries;

	while(cin >> n >> queries and (n or queries))
	{
		for(int i = 0; i < n; ++i)
			cin >> numbers[i];
		
		cout << "SET " << set++ <<":\n";
		
		for(int q = 1; q <= queries; ++q)
		{
			cin >> d >> m;

			memset(memo, -1, sizeof(memo));
			cout << "QUERY " << q << ": " << searchArrays(0, 0, 0) << "\n";
		}
	}

	return 0;
}