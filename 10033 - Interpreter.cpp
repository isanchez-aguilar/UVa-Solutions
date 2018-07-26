/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10033 - Interpreter
*/
#include <bits/stdc++.h>

using namespace std;

inline int toDigit(char c)
{
	return c - '0';
}

inline int parseInt(string s)
{
	return (toDigit(s[0]) * 10 + toDigit(s[1])) * 10 + toDigit(s[2]);
}

inline string toString(int n)
{
	string s = "000";

	s[2] = n % 10 + '0';
	n /= 10;

	s[1] = n % 10 + '0';
	n /= 10;
	
	s[0] = n % 10 + '0';

	return s;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	string ram[1000];
	string registers[10];

	cin >> testCases;
	
	cin.ignore();
	cin.ignore(); 

	while (testCases--)
	{
		fill(ram, ram + 1000, "000");
		
		string instruction;
		int currentInstruction = 0;

		while (getline(cin, instruction) and instruction.length())
		{
			ram[currentInstruction][0] = instruction[0];
			ram[currentInstruction][1] = instruction[1];
			ram[currentInstruction++][2] = instruction[2];
		}

		fill(registers, registers + 10, "000");

		char d;
		char n;
		char s;
		char a;
		bool halt = false;
		currentInstruction = 0;
		int executedInstructions = 0;
		
		while (not halt)
		{
			++executedInstructions;

			switch (ram[currentInstruction][0])
			{
				case '1':
					halt = true;
					++currentInstruction;
				break;

				case '2':
					d = ram[currentInstruction][1];
					n = ram[currentInstruction][2];

					++currentInstruction;
					registers[toDigit(d)] =  toString(toDigit(n));
				break;

				case '3':
					d = ram[currentInstruction][1];
					n = ram[currentInstruction][2];

					++currentInstruction;
					registers[toDigit(d)] = toString((parseInt(registers[toDigit(d)]) + toDigit(n)) % 1000);
				break;

				case '4':
					d = ram[currentInstruction][1];
					n = ram[currentInstruction][2];
					
					++currentInstruction;
					registers[toDigit(d)] = toString((parseInt(registers[toDigit(d)]) * toDigit(n)) % 1000);
				break;

				case '5':
					d = ram[currentInstruction][1];
					s = ram[currentInstruction][2];

					++currentInstruction;
					registers[toDigit(d)] = registers[toDigit(s)];
				break;

				case '6':
					d = ram[currentInstruction][1];
					s = ram[currentInstruction][2];

					++currentInstruction;
					registers[toDigit(d)] = toString((parseInt(registers[toDigit(d)]) + parseInt(registers[toDigit(s)])) % 1000);
				break;

				case '7':
					d = ram[currentInstruction][1];
					s = ram[currentInstruction][2];
					
					++currentInstruction;
					registers[toDigit(d)] = toString((parseInt(registers[toDigit(d)]) * parseInt(registers[toDigit(s)])) % 1000);
				break;

				case '8':
					d = ram[currentInstruction][1];
					a = ram[currentInstruction][2];

					++currentInstruction;
					registers[toDigit(d)] = ram[parseInt(registers[toDigit(a)])];
				break;

				case '9':
					s = ram[currentInstruction][1];
					a = ram[currentInstruction][2];

					++currentInstruction;
					ram[parseInt(registers[toDigit(a)])] = registers[toDigit(s)];
				break;

				case '0':
					d = ram[currentInstruction][1];
					s = ram[currentInstruction][2];

					if (parseInt(registers[toDigit(s)]) != 0)
						currentInstruction = parseInt(registers[toDigit(d)]);
					else
						++currentInstruction;
				break;
			}
		}

		cout << executedInstructions << "\n";

		if (testCases)
			cout << "\n";
	}

	return 0;
}