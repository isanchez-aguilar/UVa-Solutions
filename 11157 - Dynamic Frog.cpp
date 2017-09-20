/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11157 - Dynamic Frog
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		int n;
		int d;
		cin >> n >> d;

		int size = n + 2;
		vector<int> stone(1, 0);

		for(int i = 0; i < n; ++i)
		{
			char type;
			char ignore;
			int distance;
			cin >> type >> ignore >> distance;

			stone.push_back(distance);

			if(type == 'B')
			{
				++size;
				stone.push_back(distance);
			}
		}

		stone.push_back(d);

		int minJump = 0;

		for(int i = 3; i < size; ++i)
			minJump = max(minJump, stone[i] - stone[i - 2]);

		for(int i = 2; i < size; ++i)
			minJump = max(minJump, stone[i] - stone[i - 2]);

		cout << "Case " << t << ": " << minJump << "\n";
	}

	return 0;
}