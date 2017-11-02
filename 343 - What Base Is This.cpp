/*
*	User: Isanchez_Aguilar
*	Problem: UVA 343 - What Base Is This?
*/
#include <bits/stdc++.h>

using namespace std;

inline int getValue(char c)
{
	if(isalpha(c))
		return c - 'A' + 10;

	return c - '0';
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string x;
	string y;
	map<long long, int> x10;

	while(cin >> x >> y)
	{
		x10.clear();
		long long n;
		int largestNumberX = 2;
		int largestNumberY = 2;
		int lengthX = x.length();
		int lengthY = y.length();
		int maxLength = max(lengthX, lengthY);

		for(int i = 0; i < maxLength; ++i)
		{
			if(i < lengthX)
				largestNumberX = max(largestNumberX, getValue(x[i]) + 1);
			if(i < lengthY)
				largestNumberY = max(largestNumberY, getValue(y[i]) + 1);
		}

		for(int i = largestNumberX; i < 37; ++i)
		{
			n = 0;

			for(int j = 0; j < lengthX; ++j)
				n = n * i + getValue(x[j]);

			if(x10.count(n) == 0)
				x10[n] = i;
		}
		
		int a = INT_MAX;
		int b = INT_MAX;
		pair<int, int> base(a, b);

		for(int i = largestNumberY; i < 37; ++i)
		{
			n = 0;

			for(int j = 0; j < lengthY; ++j)
				n = n * i + getValue(y[j]);
			
			pair<int, int> auxBase(i, x10[n]);

			if(auxBase.second != 0)
			{
				if(auxBase.first > auxBase.second)
					swap(auxBase.first, auxBase.second);

				if(auxBase < base)
				{	
					b = i;
					a = x10[n];
					base = auxBase;
				}
			}
		}

		if(a == INT_MAX)
			cout << x << " is not equal to " << y << " in any base 2..36\n";
		else
			cout << x << " (base " << a << ") = " << y << " (base " << b << ")\n";
	}

	return 0;
}