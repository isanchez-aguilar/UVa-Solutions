/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12086 - Potentiometers
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 200000;

inline int getLeastSignificantBit(int number) { return number & (-number); }

class FenwickTree
{
public:
	int size;
	vector<int> sum;
	vector<int> values;

	FenwickTree(vector<int> data):size(data.size()), sum(size + 1), values(data)
	{
		for (int i = 0; i < size; ++i)
			addValue(i, data[i]);
	}

	inline void addValue(int index, int value)
	{
		++index;

		while (index <= size)
		{
			sum[index] += value;
			index += getLeastSignificantBit(index);
		}

		return;
	}

	inline void updateValue(int index, int value)
	{
		addValue(index, value - values[index]);
		values[index] = value;

		return;
	}

	inline int getSum(int left, int right) { return getSum(right) - (left == 0?0:getSum(left - 1)); }

	inline int getSum(int index)
	{
		++index;
		int total = 0;

		while (index > 0)
		{
			total += sum[index];
			index -= getLeastSignificantBit(index);
		}

		return total;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int testCase = 0;
	while (cin >> n and n)
	{
		string query;
		vector<int> resitenceValue(n);

		for (int i = 0; i < n; ++i)
			cin >> resitenceValue[i];

		FenwickTree potemtiometers(resitenceValue);
		
		if (testCase > 0)
			cout << "\n";

		cout << "Case " << ++testCase << ":\n";

		while (cin >> query and query[0] != 'E')
		{
			if (query == "M")
			{
				int left;
				int right;
				cin >> left >> right;
				cout << potemtiometers.getSum(left - 1, right - 1) << "\n";
			}
			else
			{
				int index;
				int value;
				cin >> index >> value;
				potemtiometers.updateValue(index - 1, value);
			}
		}
	}

	return 0;
}