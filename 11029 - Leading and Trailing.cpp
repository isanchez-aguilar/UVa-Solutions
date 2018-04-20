/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11029 - Leading and Trailing
*/
#include <bits/stdc++.h>

using namespace std;

long n;
long k;

inline int getLastDigits()
{
	int digits = 1;
	n %= 1000L;
	while (k > 0)
	{
		if (k & 1)
			digits = (digits * n) % 1000L;
		
		k >>= 1L;
		n = (n * n) % 1000L;
	}
	
	return digits;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long double power;
	
	int testCases;
	cin >> testCases;
	
	while (testCases--)
	{
		cin >> n >> k;
		
		power = (double)k * log10(n);
		int firstDigits = pow(10, power - floor(power)) * 100.0;
		
		cout << firstDigits << "..." << setw(3) << setfill('0') << getLastDigits() << "\n";
	}
	
	return 0;
}
