/*
*	User: Isanchez_Aguilar
*	Problem: UVA 214 - Code Generation
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	string postfix;

	while (cin >> postfix)
	{
		if (t++)
			cout << "\n";

		char operand = '\0';
		int storageSize = 0;
		bool emptyStack = true;

		for (int i = 0; i < postfix.length(); ++i)
		{
			if (postfix[i] == '+')
			{
				if (operand != '\0')
					cout << "A " << operand << "\n";
				else
					cout << "A $" << --storageSize << "\n";

				operand = '\0';
			}
			else if (postfix[i] == '-')
			{
				if (operand != '\0')
					cout << "S " << operand << "\n";
				else
					cout << "N\n" << "A $" << --storageSize<< "\n";

				operand = '\0';
			}
			else if (postfix[i] == '*')
			{
				if (operand != '\0')
					cout << "M " << operand << "\n";
				else
					cout << "M $" << --storageSize << "\n";

				operand = '\0';	
			}
			else if (postfix[i] == '/')
			{
				if (operand != '\0')
					cout << "D " << operand << "\n";
				else
				{
					cout << "ST $" << storageSize++ << "\n";
					cout << "L $" << storageSize - 2 << "\n";
					cout << "D $" << --storageSize << "\n";
					storageSize--;
				}

				operand = '\0';	
			}
			else if (postfix[i] == '@')
			{
				if (operand != '\0')
				{
					if (not emptyStack)
						cout << "ST $" << storageSize++ << "\n";

					cout << "L " << operand << "\n";
					
					operand = '\0';
					emptyStack = false;
				}

				cout << "N" << "\n";
			}
			else
			{
				if (operand != '\0')
				{
					if (not emptyStack)
						cout << "ST $" << storageSize++ << "\n";
					
					emptyStack = false;
					
					cout << "L " << operand << "\n";
				}
				
				operand = postfix[i];
			}
		}

		if (operand != '\0')
		{
			if (not emptyStack)
				cout << "ST $" << storageSize++ << "\n";

			emptyStack = true;

			cout << "L " << operand << "\n";
		}
	}

	return 0;
}