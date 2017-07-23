/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10954 - Add All
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n && n)
	{
		priority_queue<int> numbers;
		while(n--)
		{
			int temp;
			cin >> temp;
			numbers.push(-temp);
		}
		
		int cost = 0;

		while(numbers.size() > 1)
		{
			int n1 = numbers.top();
			numbers.pop();
			
			int n2 = numbers.top();
			numbers.pop();

			int sum = n1 + n2;
			numbers.push(sum);

			cost -= sum;
		}

		cout << cost << "\n";
	}

	return 0;
}