/*
*	User: Isanchez_Aguilar
*	Problem: UVA 13094 - Tobby Bones
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_BLOCKS = 777;
const int MAX_NUMBER = 600010;

// Least significant one-bit.
inline int LSOne(int n) { return n & (-n); }

int n;
int m;
int l;
int r;
int value;
int query;
int blockSize;
int bolcksNumber;
int data[MAX_NUMBER];
int bit[MAX_BLOCKS][MAX_NUMBER];

inline void SqrtDescomposition()
{
	blockSize = sqrt(n);
	fill(data, data + n, 0);
	bolcksNumber = n / blockSize + 1;

	for (int i = 0; i < bolcksNumber; ++i)
		fill(bit[i], bit[i] + MAX_NUMBER, 0);
}

inline void update(int index, int block, int value) 
{
	while (index < MAX_NUMBER)
	{
		bit[block][index] += value;
		index += LSOne(index);
	}

	return;
}

void update(int index, int value) 
{
	if (data[index] != 0)
		update(data[index], index / blockSize, -1); 
	
	update(value, index / blockSize, 1); 

	data[index] = value; 
}

inline int getLowerThan(int left, int right, int k) 
{
	int totalNumbers = 0;

	while (left < right and left % blockSize != 0 and left != 0) 
	{
		if (data[left] != 0 and data[left] <= k)
			++totalNumbers;

		++left;
	}

	while (left + blockSize <= r) 
	{
		int index = k;

		while (index > 0)
		{
			totalNumbers += bit[left / blockSize][index];
			index -= LSOne(index);
		}

		left += blockSize; 
	}

	while (left <= r) 
	{
		if (data[left] != 0 and data[left] <= k)
			++totalNumbers; 
		
		++left;
	}
	
	return totalNumbers; 
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m)
	{
		SqrtDescomposition();

		for (int i = 0; i < m; ++i)
		{
			cin >> query >> l;

			if (query == 1)
			{
				cin >> r >> value;
				cout << getLowerThan(l, r, value) << "\n";
			}
			else
			{
				cin >> value;
				update(l, value);
			}
		}
	}

	return 0; 
}