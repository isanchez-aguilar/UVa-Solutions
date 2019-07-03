#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1000000;

int data[MAX_SIZE];
int closest[MAX_SIZE];
int currentLeft[MAX_SIZE];
int currentRight[MAX_SIZE];
pair<int, int> dataIndex[MAX_SIZE];

inline bool comparator(const pair<int, int>& a, const pair<int, int>& b) { return data[a.first] < data[b.first]; }

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int q;
	while (cin >> n >> q and (n != 0 or q != 0))
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> data[i];
			dataIndex[i].first = i;
		}

		sort(dataIndex, dataIndex + n, comparator);

		int previous = 0;
		dataIndex[0].second = previous;

		for (int i = 1; i < n; ++i)
		{
			if (data[dataIndex[i].first] != data[dataIndex[i - 1].first])
				++previous;

			dataIndex[i].second = previous;
		}

		sort(dataIndex, dataIndex + n);
		fill(currentLeft, currentLeft + n, n);

		for (int i = n - 1; i > -1; --i)
		{
			currentRight[i] = currentLeft[dataIndex[i].second];
			
			currentLeft[dataIndex[i].second] = i;
		}

		closest[n - 1] = currentRight[n - 1];

		for (int i = n - 2; i > -1; --i)
			closest[i] = min(currentRight[i], closest[i + 1]);

		while (q--)
		{
			int left;
			int right;
			cin >> left >> right;

			--left;
			--right;

			if (closest[left] > right)
				cout << "OK\n";
			else
				cout << data[closest[left]] << "\n";
		}

		cout << "\n";
	}

	return 0;
}