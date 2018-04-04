/*
*   User: Isanchez_Aguilar
*   Problem: UVA 11526 - H(n)
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    int t;
	long long n;
    
    cin >> t;
	while (t--)
    {
        cin >> n;
    	long long sum = 0;
    	long long sqN = sqrt(n);
    	
    	for (int i = 1; i <= sqN; ++i)
    		sum += n / i;
    
    	cout << (sum << 1) - sqN * sqN << "\n";
    }
    
	return 0;
}