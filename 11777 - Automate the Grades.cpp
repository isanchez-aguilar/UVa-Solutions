/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11777 - Automate the Grades
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	for (int t = 1; t <= testCases; ++t)
	{
		int term1;
		int term2;
		int final;
		int attendance;
		int classTest[3];
		cin >> term1 >> term2 >> final >> attendance;

		for (int i = 0; i < 3; ++i)
			cin >> classTest[i];

		sort(classTest, classTest + 3);

		int score = term1 + term2 + final + attendance + (classTest[1] + classTest[2]) / 2;

		char note = 'A';

		if (score < 60)
			note = 'F';
		else if (score >= 60 and score < 70)
			note = 'D';
		else if (score >= 70 and score < 80)
			note = 'C';
		else if (score >= 80 and score < 90)
			note = 'B';

		cout << "Case " << t << ": " << note << "\n";
	}

	return 0;
}