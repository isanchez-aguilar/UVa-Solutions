/*
*	User: Isanchez_Aguilar
*	Problem: UVA 12541 - Birthdates
*/
#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
	int d;
	int m;
	int y;
	string name;

	Person(){}

	inline bool operator<(const Person& a)
	{
		if (y == a.y)
		{
			if (m == a.m)
			{
				if (d == a.d)
					return name < a.name;

				return d < a.d;
			}

			return m < a.m;
		}

		return y < a.y;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	Person people[n];

	for (int i = 0; i < n; ++i)
		cin >> people[i].name >> people[i].d >> people[i].m >> people[i].y;

	sort(people, people + n);

	cout << people[n - 1].name << "\n" << people[0].name << "\n";

	return 0;
}