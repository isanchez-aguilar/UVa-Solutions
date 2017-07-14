/*
*	User: Isanchez_Aguilar
*	Problem: UVA 394 - Mapmaker
*/
#include <bits/stdc++.h>

using namespace std;

class Array
{
public:
	int base;	
	int size;
	string name;	
	int dimension;
	int C0;
	vector<int> C;
	vector<int> upperBound;
	vector<int> lowerBound;
	
	void readData()
	{
		cin >> name >> base >> size >> dimension;

		C = vector<int>(dimension);
		lowerBound = vector<int>(dimension);
		upperBound = vector<int>(dimension);

		for(int i = 0; i < dimension; ++i)
			cin >> lowerBound[i] >> upperBound[i];
		
		C[dimension - 1] = size;

		C0 = base - C[dimension - 1] * lowerBound[dimension - 1];
		for(int i = dimension - 2; i > -1; --i)
		{
			C[i] = C[i + 1] * (upperBound[i + 1] - lowerBound[i + 1] + 1);
			C0 -= (C[i] * lowerBound[i]);
		}
		

		return;
	}

};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arrays;
	int references;
	map<string, int> indexs;
	cin >> arrays >> references;
	vector<Array> definedArrays(arrays);

	for(int i = 0; i < arrays; ++i)
	{
		Array current;
		current.readData();
		indexs[current.name] = i;
		definedArrays[i] = current;
	}

	for(int i = 0; i < references; ++i)
	{
		string name;
		cin >> name;
	
		int index = indexs[name];
		int address = definedArrays[index].C0;

		int dimension = definedArrays[index].dimension;

		cout << name << "[";
		for(int j = 0; j < dimension; ++j)
		{
			int id;
			cin >> id;
			address += (definedArrays[index].C[j] * id);
			
			cout << id;
			if(j + 1 < dimension)
				cout << ", ";
			else
				cout << "] = ";
		}
		cout << address << "\n";
	}
	return 0;
}