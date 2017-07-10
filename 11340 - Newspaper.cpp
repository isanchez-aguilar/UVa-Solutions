/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11340 - Newspaper
*/
#include <bits/stdc++.h>

using namespace std;

class Character
{
public:
	char c;
	int value;
	Character(char _c, int _value):c(_c), value(_value) {}
	inline bool operator<(const Character &a){ return (this->c < a.c); }
};

typedef vector<Character> vc;

int binary_search(char value, int l, int r, const vc &priceTable)
{
	while(l <= r)
	{
		int m = (r + l) >> 1;
		
		if(priceTable[m].c == value)
			return priceTable[m].value;
		if(priceTable[m].c < value)
			l = m + 1;
		else if(priceTable[m].c > value)
			r = m - 1;
	}
	return 0;
}

int main(void)
{
	int testCases;
	scanf("%d", &testCases);
	while(testCases--)
	{
		int payment = 0;
		int paidCharacters;
		vc priceTable;

		scanf("%d\n", &paidCharacters);
		int limit = paidCharacters;
		while(paidCharacters--)
		{
			char c;
			int value;
			scanf("%c %d\n", &c, &value);
			priceTable.push_back(Character(c, value));
		}

		sort(priceTable.begin(), priceTable.end());

		char c;
		int lines;
		int cents = 0;

		scanf("%d\n", &lines);
		while(lines--)
		{
			while((c = getchar()) != '\n' && c != EOF)
			{
				int value = binary_search(c, 0, limit, priceTable);
				cents += value;
			}
		}
		printf("%d.%02d$\n", cents / 100, cents % 100);
	}	

	return 0;
}