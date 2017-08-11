/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11235 - Frequent values
*/
#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
public:
	int n;
	vector<int> st;
	vector<int> data;

	inline int left(int p) { return (p << 1); }
	inline int rigth(int p) { return (p << 1) + 1; }
	inline void build(int p, int l, int r)
	{
		if(l == r)
		{
			st[p] = l;
			return;
		}

		build(left(p), l, (l + r) >> 1);
		build(rigth(p), ((l + r) >> 1) + 1, r);

		int p1 = st[left(p)];
		int p2 = st[rigth(p)];

		st[p] = (data[p1]  >= data[p2]?p1:p2);
	}
	SegmentTree(int _n):n(_n), st(_n << 2), data(_n)
	{
		int frequency = 0;
		int previous = -100001;

		for(int i = 0; i < n; ++i)
		{
			int d;
			cin >> d;

			if(previous != d)
				frequency = 0;

			previous = d;
			data[i] = ++frequency;
		}

		build(1, 0, n - 1);
	}
	inline int rmq(int p, int l, int r, int i, int j)
	{
		if(i > r || j < l)
			return -1;
		
		if(l == r)
			return st[p];
		
		if(i <= l && j >= r && data[st[p]] <= st[p] - i + 1)
			return st[p];

		int p1 = rmq(left(p), l, (l + r) >> 1, i, j);
		int p2 = rmq(rigth(p), ((l + r) >> 1) + 1, r, i, j);

		if(p1 == -1)
			return p2;

		if(p2 == -1)
			return p1;

		return (min(p1 - i + 1, data[p1]) >= min(p2 - i + 1, data[p2])?p1:p2);		
	}
	inline int rmq(int i, int j)
	{
		int p = rmq(1, 0, n - 1, i, j);
		return min(p - i + 1, data[p]);
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n && n)
	{
		int q;
		cin >> q;

		SegmentTree st(n);
		
		for(int i = 0; i < q; ++i)
		{
			int a;
			int b;
			cin >> a >> b;
			
			cout << st.rmq(a - 1, b - 1) << "\n";
		}
	}

	return 0;
}