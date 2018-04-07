/*
*	User: Isanchez_Aguilar
*	Problem: UVA 382 - Perfection
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cout << "PERFECTION OUTPUT\n";

	while (cin >> n and n)
	{
		int sum = 0;
		int half = n >> 1;
		
		for (int i = 1; i <= half; ++i)
			sum += (n % i?0:i);

		cout << setw(5) << n << "  " << (sum == n?"PERFECT":(sum < n?"DEFICIENT":"ABUNDANT")) << "\n";
	}

	cout << "END OF OUTPUT\n";

	return 0;
}