/*
*	User: Isanchez_Aguilar
*	Problem: UVA 612 - DNA Sorting
*/
#include <bits/stdc++.h>

using namespace std;
 
class Sequence
{
public:
	string s;
	int measure;

	inline void setMeasure()
	{
		measure = 0;
	 
		for(int i = 0; s[i]; ++i)
		{
			for(int j = i + 1; s[j]; ++j)
			{
				if(s[j] < s[i])
					++measure;
			}
		}
	}
};

inline bool comp(const Sequence &a, const Sequence &b) { return (a.measure < b.measure); }

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int testCases;
	cin >> testCases;
 
	while(testCases--)
	{
		int n;
		int m;
		cin >> n >> m;

 		vector<Sequence> data(m);
		for(int i = 0; i < m; ++i)
		{
			cin >> data[i].s;
			data[i].setMeasure();
		}
 
		stable_sort(data.begin(), data.end(), comp);
 
		if(t++)
			cout << "\n";
 
		for(int i = 0; i < m; ++i)
			cout << data[i].s << endl;
	}
 
	return 0;
}