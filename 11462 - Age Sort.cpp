/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11462 - Age Sort
*/
#include <bits/stdc++.h>

using namespace std;

void fastscan(int &number)
{
	register int c;

	number = 0;
	c = getchar();

	for (; c > 47 && c < 58; c = getchar())
		number = number * 10 + c - 48;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	
	fastscan(n);
	while(n)
	{
		short ages[100] = {0};
		for(int i = 0; i < n; ++i)
		{
			int age;
			fastscan(age);
			++ages[age];
		}

		for(int i = 1; n && i < 100; ++i)
		{
			int frequency = ages[i];
			n -= frequency;

			for(int j = 0; j < frequency; ++j)
			{
				cout << i;
				if(n || j < frequency - 1)
					cout << " ";
				else
					cout << "\n";
			}
		}
	
		fastscan(n);
	}

	return 0;
}