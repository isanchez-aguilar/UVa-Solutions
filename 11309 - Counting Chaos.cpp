/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11309 - Counting Chaos
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef set<ii> sii;

inline bool isPalindrome(int h, int m)
{
	string sReverse = "";
	
	if (h == 0)
	{
		while (m)
		{
			char c = m % 10 + '0';
			sReverse += c;
			m /= 10;
		}

		string s(sReverse);
		reverse(s.begin(), s.end());

		return s == sReverse;
	}

	while (h)
	{
		char c = h % 10 + '0';
		sReverse += c;
		h /= 10;
	}

	int mAux = m;
	string s = "";

	while (m)
	{
		char c = m % 10 + '0';
		s += c;
		m /= 10;	
	}

	if (mAux < 10)
		s += "0";
	
	s += sReverse;

	sReverse = s;
	reverse(s.begin(), s.end());
	
	return s == sReverse;
}

inline void printTime(ii time)
{
	int h = time.first;
	int m = time.second;

	if (h < 10)
		cout << "0";
	
	cout << h << ":";
	
	if (m < 10)
		cout << "0";
	
	cout << m << "\n";

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h = 0;
	int m = 0;
	sii palindromicsTime;

	while (h < 24)
	{
		if (isPalindrome(h, m))
			palindromicsTime.insert(ii(h, m));

		if (++m == 60)
		{
			++h;
			m = 0;
		}
	}

	int n;
	char dots;
	
	cin >> n;
	while (n--)
	{
		cin >> h >> dots >> m;	
		
		ii time(h, m);
		sii::iterator i = palindromicsTime.lower_bound(time);

		if (*i == time)
		{
			++i;
			if (i == palindromicsTime.end())
				cout << "00:00\n";
			else
				printTime(*i);
		}
		else
		{
			if (i == palindromicsTime.end())
				cout << "00:00\n";
			else
				printTime(*i);
		}
	}

	return 0;
}