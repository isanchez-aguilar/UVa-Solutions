/*
*	User: Isanchez_Aguilar
*	Problem: UVA 100 - The 3n + 1 problem
*/
#include <bits/stdc++.h>

#define MAX 1000001
#define getLeft(n) n<<1
#define getRight(n) (n<<1)+1

using namespace std;

vector<int> data(MAX, -1);
vector<int> segment(MAX << 2);

inline int query(int l, int r, int index, int i, int j)
{
	if (l > j or r < i)
		return -1;
	
	if (i <= l and j >= r)
		return segment[index];

	int middle = (l + r) >> 1;

	int q1 = query(l, middle, getLeft(index), i, j);
	int q2 = query(middle + 1, r, getRight(index), i, j);

	return max(q1, q2);
}

inline void build(int l, int r, int index)
{
	if (l == r)
	{
		segment[index] = data[l];
		return;
	}	

	int middle = (l + r) >> 1;

	build(l, middle, getLeft(index));
	build(middle + 1, r, getRight(index));

	segment[index] = max(segment[getLeft(index)], segment[getRight(index)]);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i;
	int j;

	data[1] = 1;
	data[2] = 2;

	for (int a = 3; a < MAX; ++a)
	{
		int length = 0;
		long long n = a;

		while (n != 1)
		{
			if (n & 1)
			{
				++length;
				n = (3 * n + 1 ) >> 1;
			}
			else
				n >>= 1;

			++length;

			if (n < MAX and data[n] != -1)
			{
				length += data[n];
				break;
			}
		}

		data[a] = length;
	}
	
	build(0, MAX - 1, 1);

	while (cin >> i >> j)
	{
		int a = i;
		int b = j;

		if (i > j)
			swap(a, b);

		cout << i << " " << j << " " << query(0, MAX - 1, 1, a, b) << "\n";
	}

	return 0;
}