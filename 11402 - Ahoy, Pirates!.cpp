/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11402 - Ahoy, Pirates!
*/
#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
public:
	int n;
	vector<int> st;
	vector<int> data;
	vector<int> lazy;

	inline int left(int p) { return (p << 1); }
	inline int rigth(int p) { return (p << 1) + 1; }
	inline void build(int p, int l, int r)
	{
		lazy[p] = 0;
		if(l == r)
		{
			st[p] = data[l];
			return;
		}

		int L = left(p);
		int R = rigth(p); 
		int middle = (l + r) >> 1;

		build(L, l, middle);
		build(R, middle + 1, r);

		st[p] = st[L] + st[R];

		return;
	}
	SegmentTree(int _n, const string &s):n(_n), st(_n << 3), data(_n), lazy(_n << 3)
	{
		for(int i = 0; i < n; ++i)
			data[i] = (s[i] == '0'?0:1);

		build(1, 0, n - 1);
	}
	inline int inverseStatus(int status)
	{
		switch(status)
		{
			case 1:
				return 2;
			case 2:
				return 1;
			case 3:
				return 0;
			default:
				return 3;
		}
	}
	inline void update(int p, int l, int r)
	{
		if(!lazy[p])
			return;
		
		switch(lazy[p])
		{
			case 1:
				st[p] = r - l + 1;
			break;
			case 2:
				st[p] = 0;
			break;
			default:
				st[p] = r - l + 1 - st[p];
		}

		if(l != r)
		{
			if(lazy[p] == 1 || lazy[p] == 2)
			{
				lazy[left(p)] = lazy[p];
				lazy[rigth(p)] = lazy[p];
			}
			else
			{
				lazy[left(p)] = inverseStatus(lazy[left(p)]);
				lazy[rigth(p)] = inverseStatus(lazy[rigth(p)]);
			}
		}

		lazy[p] = 0;

		return;
	}
	inline void mutateToBucaneer(int p, int l, int r, int i, int j)
	{
		if(lazy[p])
			update(p, l, r);
		
		if(l > j || r < i)
			return;

		if(l >= i && j >= r)
		{
			st[p] = r - l + 1;
			lazy[left(p)] = 1;
			lazy[rigth(p)] = 1;

			return;
 		}

 		int L = left(p);
 		int R = rigth(p);
 		int middle = (l + r) >> 1;

 		mutateToBucaneer(L, l, middle, i, j);
 		mutateToBucaneer(R, middle + 1, r, i, j);

 		st[p] = st[L] + st[R];

 		return;
	}
	inline void mutateToBarbary(int p, int l, int r, int i, int j)
	{
		if(lazy[p])
			update(p, l, r);
		
		if(l > j || r < i)
			return;

		if(l >= i && j >= r)
		{
			st[p] = 0;
			lazy[left(p)] = 2;
			lazy[rigth(p)] = 2;

			return;
 		}

 		int L = left(p);
 		int R = rigth(p);
 		int middle = (l + r) >> 1;
 	
 		mutateToBarbary(L, l, middle, i, j);
 		mutateToBarbary(R, middle + 1, r, i, j);

 		st[p] = st[L] + st[R];

 		return;	
	}
	inline void inverse(int p, int l, int r, int i, int j)
	{
		if(lazy[p])
			update(p, l, r);
		
		if(l > j || r < i)
			return;

		if(l >= i && j >= r)
		{
			st[p] = r - l + 1 - st[p];
			lazy[left(p)] = inverseStatus(lazy[left(p)]);
			lazy[rigth(p)] = inverseStatus(lazy[rigth(p)]);

			return;
 		}

 		int L = left(p);
 		int R = rigth(p);
 		int middle = (l + r) >> 1;
 	
 		inverse(L, l, middle, i, j);
 		inverse(R, middle + 1, r, i, j);

 		st[p] = st[L] + st[R];

 		return;	
	}
	inline int rsq(int p, int l, int r, int i, int j)
	{
		if(lazy[p])
			update(p, l, r);
		
		if(l > j || r < i)
			return 0;

		if(l >= i && j >= r)
			return st[p];

 		int middle = (l + r) >> 1;
 		int L = rsq(left(p), l, middle, i, j);
 		int R = rsq(rigth(p), middle + 1, r, i, j);

 		return L + R;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for(int t = 1; t <= testCases; ++t)
	{
		cout << "Case " << t << ":\n";

		int lines;
		string soldiers("");

		cin >> lines;
		while(lines--)
		{
			string s;
			int concatenations;
			
			cin >> concatenations >> s;

			while(concatenations--)
				soldiers += s;
		}

		int queries;
		int godQueries = 0;
		SegmentTree st((int)soldiers.length(), soldiers);

		cin >> queries;
		while(queries--)
		{
			int a;
			int b;
			char action;
			cin >> action >> a >> b;

			switch(action)
			{
				case 'F':
					st.mutateToBucaneer(1, 0, st.n - 1, a, b);
				break;
				case 'E':
					st.mutateToBarbary(1, 0, st.n - 1, a, b);
				break;
				case 'I':
					st.inverse(1, 0, st.n - 1, a, b);
				break;
				default:
					cout << "Q" << ++godQueries << ": " << st.rsq(1, 0, st.n - 1, a, b) << "\n";
			}
		}

	}

	return 0;
}