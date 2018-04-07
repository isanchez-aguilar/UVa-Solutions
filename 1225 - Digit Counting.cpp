/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1225 - Digit Counting
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int testCases;
    cin >> testCases;
    
    while (testCases--)
    {
        cin >> n;
        int frequency[10];
        fill(frequency, frequency + 10, 0);
        
        for (int i = 1; i <= n; ++i)
        {
            int currentNumber = i;
            
            while (currentNumber)
            {
                ++frequency[currentNumber % 10];
                currentNumber /= 10;
            }
        }
        
        for (int i = 0; i < 10; ++i)
            cout << frequency[i] << (i + 1 == 10?"\n":" ");
    }
    
	return 0;
}