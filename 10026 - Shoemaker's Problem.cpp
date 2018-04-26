/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10026 - Shoemaker's Problem
*/
#include <bits/stdc++.h>

using namespace std;

class Job
{
public:
	int i;
	int d;
	int fine;

	inline bool operator<(const Job &other) const
	{
		if (d * other.fine != other.d * fine)
			return d * other.fine < other.d * fine;
		
		return i < other.i;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	string sep = "";

	cin >> testCases;
	while (testCases--)
	{
		int n;
		cin >> n;

		vector<Job> jobs(n);
		
		for (int i = 0; i < n; ++i)
		{
			jobs[i].i = i + 1;
			cin >> jobs[i].d >> jobs[i].fine;
		}
		
		sort(jobs.begin(), jobs.end());
		
		cout << jobs[0].i;

		for (int i = 1; i < n; ++i)
			cout << ' ' << jobs[i].i;

		cout << '\n';

		if (testCases)
			cout << "\n";
	}

	return 0;
}